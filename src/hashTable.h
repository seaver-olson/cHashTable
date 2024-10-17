typedef struct{
	char* key;
	char* value;
}htItem;

typedef struct{
	int size;
	int count;
	htItem** items;
}HashTable;

void insert(hashTable* ht, char* key, char* value);
char* search(hashTable* ht, char* key);
void delete(hashTable* h, char* key);

