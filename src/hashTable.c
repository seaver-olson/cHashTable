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

static int hash(char* s, int a, int m){
	long hash = 0;
	int len = 0;
	for(int i =0;s[i]!='\0';i++){
		len++;
	}
	for(int i =0;i<len_s;i++){
		hash+=(long)pow(a,len-(i+1))*s[i];
		hash %=m;
	}
	return (int)hash;
}

static int getHash(char*  s, int nb, int attempt){
	return (hash(s,HT_PRIME_1,nb) +(attempt*(hash(s,HT_PRIME_2,nb)+1)))%nb;
}

void insert(HashTable* ht,  char* key, char* value){

}
char* search(HashTable* ht, char* key){
	return NULL;
}
static htItem* HT_DELETED_ITEM = {NULL,NULL};

void delete(HashTable* ht, char* key){
	
}
