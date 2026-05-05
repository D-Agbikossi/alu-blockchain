#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <stdint.h>

#include "hblk_crypto.h"

/**
 * ec_to_pub - extracts the public key from an EC_KEY structure
 * @key: pointer to the EC_KEY structure
 * @pub: buffer to store public key (in EC_PUB_LEN bytes)
 * 
 * Return: pointer to pub, or NULL on failure
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
    const EC_POINT *point;
    const EC_GROUP *group;

    if (key == NULL || pub == NULL)
        return NULL;

    /* Get group and public point */
    group = EC_KEY_get0_group(key);
    point = EC_KEY_get0_public_key(key);

    if (group == NULL || point == NULL)
        return NULL;

    /* Convert public key to uncompressed octet form */
    if (EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED, pub, EC_PUB_LEN, NULL) == 0)
        return NULL;

    return pub;
}
