#ifndef FILEREADER_H
#define FILEREADER_H

#define FILE_ERROR 0
#define FILE_SUCCESS 1

/**
 * @brief Read a file which was already formated
 * 
 * @param path the path of the file
 * @param S the quantity of the jam
 * @param k the number of the type of jam-jars
 * @param V an array of the capacities of jam-jars
 * @return int : return FILE_SUCCESS if successful, or FILE_ERROR if the file reading is error
 */
int readfile(const char* path, int* S, int* k, int** V);

#endif // FILEREADER_H