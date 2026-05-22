CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -I. -Iprovided/ -I../../crypto -L../../crypto -lhblk_crypto -lllist -lssl -lcrypto -pthread
CFLAGS += -Wno-deprecated-declarations

SRC0 = blockchain_create.c blockchain_deserialize.c blockchain_destroy.c \
       blockchain_serialize.c block_create.c \
       block_destroy.c block_hash.c block_is_valid.c

OBJ0 = $(SRC0:.c=.o)
NAME0 = libhblk_blockchain.a

.PHONY: clean oclean fclean libhblk_blockchain.a

clean:
	$(RM) *~ $(OBJ0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

# Build objects explicitly (this Makefile previously relied on a builtin rule)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libhblk_blockchain.a: $(OBJ0)
	ar rcs $(NAME0) $(OBJ0)

