#ifndef ALGOS_H
#define ALGOS_H

#define COMPATIBLE 1
#define SHOW 1
#define HIDE 0
#define Inf 999999

/**
 * @brief Algorithm of recursion
 * 
 * @param V an array of the capacities of jam-jars
 * @param k length of the sequence of jam-jars capacities
 * @param s the quantity of the jam
 * @param i last index of the jam-jars capacities
 * @param out_A array of numbers of jam-jars
 * @return int : The total number of jam-jars
 */
int algo_I(int* V, int k, int s, int i, int** out_A);

/**
 * @brief Optimised Algorithm
 * 
 * @param V an array of the capacities of jam-jars
 * @param k length of the sequence of jam-jars capacities
 * @param S the quantity of the jam
 * @param i last index of the jam-jars capacities
 * @param out_A array of numbers of jam-jars
 * @return int : The total number of jam-jars
 */
int algo_II(int* V, int k, int S, int i, int** out_A);

/**
 * @brief Greedy algorithme (Algorithme glouton)
 * 
 * @param V an array of the capacities of jam-jars
 * @param k length of the sequence of jam-jars capacities
 * @param s the quantity of the jam
 * @param i last index of the jam-jars capacities
 * @param out_A array of numbers of jam-jars
 * @return int : The total number of jam-jars
 */
int algo_III(int* V, int k, int s, int i, int** out_A);

/**
 * @brief launch the algo, then show the result in terminal
 * 
 * @param num_algo number of algorithmr
 * @param S the total quantity of the jam
 * @param V an array of the capacities of jam-jars
 * @param k length of the sequence of jam-jars capacities
 * @param showRasult
 */
void launch(int num_algo, int S, int* V, int k, int showRasult);

/**
 * @brief test if the greedy algorithme is compatible
 * 
 * @param k 
 * @param V 
 * @return int 
 */
int testGloutonCompatible(int k, int* V);



/**
 * @brief Print out the statistic result for the two algorithm
 * 
 * @param p_max max size of jam-jars
 * @param f a reasonable and big enough number
 * @param k the total number of jam-jars
 * @param length_stat the total number of statistic
 */
void showStatistique(int p_max, int f, int k, int length_stat);

#endif // ALGOS_H