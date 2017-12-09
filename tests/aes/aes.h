/********************************************************************************************
* Header defining the APIs for AES256
*********************************************************************************************/

#ifndef __AES_H
#define __AES_H

#include <stdint.h>
#include <stdlib.h>

/**
 * Function to fill a key schedule given an initial key.
 *
 * @param key            Initial Key.
 * @param schedule       Abstract data structure for a key schedule.
 */
void AES256_load_schedule(const uint8_t *key, void *schedule);

/**
 * Same as AES256_ECB_enc() except a schedule generated by
 * AES256_load_schedule() is passed rather than a key. This is faster
 * if the same schedule is used for multiple encryptions since it does
 * not have to be regenerated from the key.
 */
void AES256_ECB_enc_sch(const uint8_t *plaintext, const size_t plaintext_len, const void *schedule, uint8_t *ciphertext);

/**
 * Function to free a key schedule.
 *
 * @param schedule       Schedule generated with AES256_load_schedule().
 */
void AES256_free_schedule(void *schedule);

#endif
