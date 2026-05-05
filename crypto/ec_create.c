#include <openssl/ec.h>
#include <openssl/obj_mac.h>

/**
 * ec_create - creates a new EC key pair using secp256k1
 *
 * Return: pointer to EC_KEY, or NULL on failure
 */
EC_KEY *ec_create(void)
{
    EC_KEY *key = NULL;

    /* Create EC_KEY structure with secp256k1 curve */
    key = EC_KEY_new_by_curve_name(NID_secp256k1);
    if (key == NULL)
        return NULL;

    /* Generate private + public key */
    if (EC_KEY_generate_key(key) != 1)
    {
        EC_KEY_free(key);
        return NULL;
    }

    return key;
}
