#include <stdlib.h>
#include "hashTable.h"

static htItem* newItem(char* k, char* v){
	htItem* i = malloc(sizeof(htItem));//allocate space for pair
	i->key = k;
	i->value = v;
	return i;
}

HashTable* newTable(){
	HashTable* ht = malloc(sizeof(HashTable));
	ht->size = 53;
	ht->count = 0;
	ht->items = calloc((size_t)ht->size, sizeof(htItem*));//zeros for days
	return ht;
}

static void delItem(htItem* item){
	free(item->key);
	free(item->value);
	free(item);
}

void delHashTable(HashTable* ht){
	for (int i = 0; i < ht->size; i++){
		htItem* item = ht->items[i];
		if (item != NULL){
			delItem(item);
		}
	}
	free(ht->items);
	free(ht);
}

