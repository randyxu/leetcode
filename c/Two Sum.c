/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define BUCKETSIZE 1001

typedef struct hashNode {
    int index;
    int value;
    struct hashNode *next;
} hashNode_t;

typedef struct hashTable {
    hashNode_t *head;
} hashTable_t;


void initHashTable(hashTable_t *hashTable) {
    for (int i = 0; i < BUCKETSIZE; i++) {
        hashTable[i].head = NULL;
    }
    return;
}

void insertToHashTable(hashTable_t *hashTable, int index, int value) {
    hashNode_t *newNode = (hashNode_t *)malloc(sizeof(hashNode_t));
    newNode->index = index;
    newNode->value = value;
    newNode->next = NULL;
  
    int key = value % BUCKETSIZE;
    if (key < 0) key = 0 - key;  
    hashNode_t *ptr = hashTable[key].head;

    //hashTable[value % BUCKETSIZE].head = newNode;
    if (ptr == NULL) {
        hashTable[key].head = newNode;
    }
    else {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }
    
    return;
}

int searchInHashTable(hashTable_t *hashTable, int value) {
    int key = value % BUCKETSIZE;
    if (key < 0) key = 0 - key;
    hashNode_t *ptr = hashTable[key].head;
    while (ptr != NULL) {
        if (ptr->value == value)
            return ptr->index;
        ptr = ptr->next;
    }

    return -1;
}


/*void printHashTable(hashTable_t *hashTable) {
    hashNode_t * ptr = NULL;
    printf("printing...\n");
    for (int i = 0; i < BUCKETSIZE; i++) {
        printf("%d:", i);
        ptr = hashTable[i].head;
        while (ptr) {
            printf("%d~", ptr->value);
            ptr = ptr->next;
        }
        printf("\n");
    }
        
}*/


int* twoSum(int* nums, int numsSize, int target) {
    static int ret[2];
    static hashTable_t hashTable[BUCKETSIZE];
    
    initHashTable(hashTable);
    for (int i = 0; i < numsSize; i++)
        insertToHashTable(hashTable, i, nums[i]);
        
    //printHashTable(hashTable);
    
    for (int i = 0; i < numsSize; i++) {
        ret[0] = i;
        ret[1] = searchInHashTable(hashTable, target - nums[i]);
        if (ret[1] == ret[0]) continue;
        if (ret[1] != -1) break;
    }
    
    return ret;
}