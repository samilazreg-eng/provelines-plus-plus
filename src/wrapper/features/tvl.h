
void loadFeatureModelDimacs(char* clauseFile, char* mappingFile); // Builds the FD formula from dimacs files.
int loadFeatureModel(char* filename, char* filter); // Add 'filter' as constraint to a TVL model, feed it into the TVL library, and builds the corresponding FD formula.
ptBoolFct getFeatureModelClauses(); // Returns the previously built FD formula (that is, the "base FD").
int getFeatureID(char* name); // Returns the ID mapped to feature 'name'
char* getFeatureIDName(int id); // Returns the feature name mapped to ID 'id'.
int getNbFeatures(); // Returns highest feature ID
int createMapping(char * name); // Returns the ID mapped to feature 'name'. Iff the mapping does not already exist, it is created.
