#include <stddef.h>
#include <stdint.h>
#include <openssl/sha.h>

/**
 * sha256 - computes SHA-256 hash of a byte sequence
 * @s: input data
 * @len: length of input data
 * @digest: buffer to store result (must be SHA256_DIGEST_LENGTH bytes)
 *
 * Return: pointer to digest, or NULL on failure
 */
uint8_t *sha256(int8_t const *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
    if (digest == NULL)
        return NULL;

    if (s == NULL)
        return NULL;

    /* Compute hash */
    if (SHA256((unsigned char *)s, len, digest) == NULL)
        return NULL;

    return digest;
}
