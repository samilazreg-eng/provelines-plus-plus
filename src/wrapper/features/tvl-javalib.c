#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "main.h"
#include "list.h"
#include "boolFct.h"
#include "tvl.h"

ptBoolFct _featureModelClauses;
ptLList _featureIDMapping;
int _nbFeatures = 0;
int maxId = 0;

void loadFeatureModelDimacs(char* clauseFile, char* mappingFile) {
	_featureModelClauses = dimacsFileToBool(clauseFile);
	if(_featureModelClauses == NULL) failure("Could not find dimacs clauses file.\n");

	FILE* fMappingFile = fopen(mappingFile, "r");
	char buffer[1024];
	int id;
	int* pId;
	char* fname;
	if(fMappingFile == NULL) failure("Could not find dimacs mapping file.\n");
	else {
		while(fgets(buffer, 1024, fMappingFile) != NULL) {
			fname = malloc(sizeof(char) * 40);
			pId = malloc(sizeof(int));
			if(!fname || !pId) failure("Out of memory (parsing dimacs file).\n");
			if(sscanf(buffer, "%d %s", &id, fname) == 2) {
				*pId = id;
				maxId = maxId >= id ? maxId : id;
				_featureIDMapping = llistAdd(_featureIDMapping, fname, pId);
				_nbFeatures++;
			} else {
				free(fname);
				free(pId);
			}
		}
		fclose(fMappingFile);
	}
}

int loadFeatureModel(char* filename, char* filter) {
	if(copyFile(filename, "__workingfile.tvl")) {
		if(filter != NULL) {
			FILE* fWorkingFile = fopen("__workingfile.tvl", "r");
			char* rootName;
			char buffer[1024];
			byte foundRoot = false;
			while(!foundRoot && fgets(buffer, 1024, fWorkingFile) != NULL) {
				rootName = malloc(sizeof(char) * 40);
				if(!rootName) failure("Out of memory (loading feature model).\n");
				if(sscanf(buffer, "root %s {", rootName) == 1) foundRoot = true;
				else free(rootName);
			}
			fclose(fWorkingFile);

			if(!foundRoot) failure("Could not find the root feature in your TVL file.  Please try again after moving it to the top of the file.\n");
			else {
				char newLine[9 + strlen(rootName) + strlen(filter)];
				sprintf(newLine, "\n%s {\n\t%s;\n}\n", rootName, filter);
				FILE* fWorkingFile = fopen("__workingfile.tvl", "a");
				fwrite(newLine, sizeof(char), 9 + strlen(rootName) + strlen(filter), fWorkingFile);
				fclose(fWorkingFile);
				free(rootName);
			}
		}

		char command[90 + strlen(path) + 1];
		sprintf(command, "java -jar %slib/tvl/TVLParser.jar -dimacs __mapping.tmp __clauses.tmp __workingfile.tvl", path);
		if(system(command) != 0) {
			if(!keepTempFiles) remove("__workingfile.tvl");
			return 0;
		} else {
			loadFeatureModelDimacs("__clauses.tmp", "__mapping.tmp");
			if(!keepTempFiles) remove("__workingfile.tvl");
			if(!keepTempFiles) remove("__mapping.tmp");
			if(!keepTempFiles) remove("__clauses.tmp");
			return 1;
		}
	}
}

ptBoolFct getFeatureModelClauses() {
	return _featureModelClauses;
}

int getFeatureID(char* name) {
	ptLList id = llistFind(_featureIDMapping, name);
	if(id == NULL) return -1;
	else return *((int*) (id->value));
}

char* getFeatureIDName(int id) {
	ptLList node = _featureIDMapping;
	while(node != NULL) {
		if(*(int *) node->value == id) return node->label;
		node = node->next;
	}
	return NULL;
}

int getNbFeatures() {
	return _nbFeatures;
}

int createMapping(char * name) {
	int id = getFeatureID(name);
	if(id != -1) {
		return id;
	}
	int * pId = (int *) malloc(sizeof(int));
	*pId = maxId+1;
	maxId++;
	int length = strlen(name);
	char * pname = (char*)malloc((length+1)*sizeof(char));
	strcpy(pname,name);
	_featureIDMapping = llistAdd(_featureIDMapping, pname, pId);
	return *pId;
}
