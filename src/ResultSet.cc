#include "zdbmm.h"

ZDB::ResultSet::ResultSet(ResultSet_T resultSet) {
    internal = resultSet;
}
int ZDB::ResultSet::getColumnCount() {
    RETURN ResultSet_getColumnCount(internal);
}
const char *ZDB::ResultSet::getColumnName(int columnIndex) {
    RETURN ResultSet_getColumnName(internal, columnIndex);
}
long ZDB::ResultSet::getColumnSize(int columnIndex) {
    RETURN ResultSet_getColumnSize(internal, columnIndex);
}
int ZDB::ResultSet::next() {
    RETURN ResultSet_next(internal);
}
const char *ZDB::ResultSet::getString(int columnIndex) {
    RETURN ResultSet_getString(internal, columnIndex);
}
const char *ZDB::ResultSet::getStringByName(const char *columnName) {
    RETURN ResultSet_getStringByName(internal, columnName);
}
int ZDB::ResultSet::getInt(int columnIndex) {
    RETURN ResultSet_getInt(internal, columnIndex);
}
int ZDB::ResultSet::getIntByName(const char *columnName) {
    RETURN ResultSet_getIntByName(internal, columnName);
}
long long int ZDB::ResultSet::getLLong(int columnIndex) {
    RETURN ResultSet_getLLong(internal, columnIndex);
}
long long int ZDB::ResultSet::getLLongByName(const char *columnName) {
    RETURN ResultSet_getLLongByName(internal, columnName);
}
double ZDB::ResultSet::getDouble(int columnIndex) {
    RETURN ResultSet_getDouble(internal, columnIndex);
}
double ZDB::ResultSet::getDoubleByName(const char *columnName) {
    RETURN ResultSet_getDoubleByName(internal, columnName);
}
const void *ZDB::ResultSet::getBlob(int columnIndex, int *size) {
    RETURN ResultSet_getBlob(internal, columnIndex, size);
}
const void *ZDB::ResultSet::getBlobByName(const char *columnName, int *size) {
    RETURN ResultSet_getBlobByName(internal, columnName, size);
}
time_t ZDB::ResultSet::getTimestamp(int columnIndex) {
    RETURN ResultSet_getTimestamp(internal, columnIndex);
}
time_t ZDB::ResultSet::getTimestampByName(const char *columnName) {
    RETURN ResultSet_getTimestampByName(internal, columnName);
}
struct tm ZDB::ResultSet::getDateTime(int columnIndex) {
    RETURN ResultSet_getDateTime(internal, columnIndex);
}
struct tm ZDB::ResultSet::getDateTimeByName(const char *columnName) {
    RETURN ResultSet_getDateTimeByName(internal, columnName);
}
