#ifndef ANALYSE_H
#define ANALYSE_H

/**
 * @brief Get the Expo Capacity System
 * 
 * @param k length of the system
 * @param d power
 * @return int* 
 */
int* getExpocapacitySystem(int k, int d);

/**
 * @brief Get the capacity system
 * 
 * @param k length of the system
 * @param p_max max capacity of jam-jars
 * @return int* 
 */
int* getRandomCapacitySystem(int k, int p_max);

/**
 * @brief 
 * 
 * @param num_algo No. algo
 * @param d base of capacity
 * @param S_max max S
 * @param k_max max k
 */
void stat_time_algo(int num_algo, int d, int S_max, int k_max);

#endif