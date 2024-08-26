#ifndef QUERY_H
#define QUERY_H

#include "storage.h"

typedef enum {
    CREATE_DATABASE,
    CREATE_TABLE,
    INSERT_INTO,
    SELECT_FROM
} QueryType;

typedef struct {
    QueryType type;
    char databaseName[MAX_NAME_LENGTH];
    char tableName[MAX_NAME_LENGTH];
    void* rowData[MAX_NAME_LENGTH];
    uint32_t dataCount;
} Query;

Query* parseCreateDatabaseQuery(const char* queryStr);
Query* parseCreateTableQuery(const char* queryStr);
Query* parseInsertQuery(const char* queryStr);
Query* parseSelectQuery(const char* queryStr);
void executeCreateDatabaseQuery(Database* db, Query* query);
void executeCreateTableQuery(Database* db, Query* query);
void executeInsertQuery(Database* db, Query* query);
void executeSelectQuery(const Database* db, const Query* query);

#endif