#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <stdint.h>

#include "hblk_crypto.h"

/**
 * ec_from_pub - creates an EC_KEY from a public key buffer
 * @pub: buffer containing uncompressed public key (65 bytes)
 *
 * Return: pointer to EC_KEY, or NULL on failure
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
    EC_KEY *key = NULL;
    const EC_GROUP *group;
    EC_POINT *point = NULL;

    if (pub == NULL)
        return NULL;

    /* Create key with secp256k1 curve */
    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (key == NULL)
        return NULL;

    group = EC_KEY_get0_group(key);
    if (group == NULL)
        goto fail;

    /* Create a point on the curve */
    point = EC_POINT_new(group);
    if (point == NULL)
        goto fail;

    /* Convert bytes → EC_POINT */
    if (EC_POINT_oct2point(group, point, pub, EC_PUB_LEN, NULL) != 1)
        goto fail;

    /* Set public key into EC_KEY */
    if (EC_KEY_set_public_key(key, point) != 1)
        goto fail;

    EC_POINT_free(point);
    return key;

fail:
    if (point)
        EC_POINT_free(point);
    if (key)
        EC_KEY_free(key);
    return NULL;
}
