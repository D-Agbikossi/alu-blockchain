#include "blockchain.h"

/**
 * block_destroy - deletes an exisiting block
 *
 * @block: pointer to the block to delete
 */
void block_destroy(block_t *block)
{
	free(block);
}