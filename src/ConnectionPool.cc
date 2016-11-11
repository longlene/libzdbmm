#include "zdbmm.h"

ZDB::ConnectionPool::ConnectionPool(ZDB::URL* url) {
  this->url = url;
    internal = ConnectionPool_new((URL_T) url->value());
};

ZDB::ConnectionPool::~ConnectionPool() {
    ConnectionPool_free(&internal);
}

ZDB::URL* ZDB::ConnectionPool::getURL() {
  return url;
}

void ZDB::ConnectionPool::setInitialConnections(int connections) {
    ConnectionPool_setInitialConnections(internal, connections);
}

int ZDB::ConnectionPool::getInitialConnections() {
    RETURN ConnectionPool_getInitialConnections(internal);
}

void ZDB::ConnectionPool::setMaxConnections(int maxConnections) {
    ConnectionPool_setMaxConnections(internal, maxConnections);
}

int ZDB::ConnectionPool::getMaxConnections() {
    RETURN ConnectionPool_getMaxConnections(internal);
}

void ZDB::ConnectionPool::setConnectionTimeout(int connectionTimeout) {
    ConnectionPool_setConnectionTimeout(internal, connectionTimeout);
}

int ZDB::ConnectionPool::getConnectionTimeout() {
    RETURN ConnectionPool_getConnectionTimeout(internal);
}

void ZDB::ConnectionPool::setAbortHandler(void(*abortHandler)(const char *error)) {
    ConnectionPool_setAbortHandler(internal, abortHandler);
}

void ZDB::ConnectionPool::setReaper(int sweepInterval) {
    ConnectionPool_setReaper(internal, sweepInterval);
}

int ZDB::ConnectionPool::size() {
    RETURN ConnectionPool_size(internal);
}

int ZDB::ConnectionPool::active() {
    RETURN ConnectionPool_active(internal);
}

void ZDB::ConnectionPool::start() {
    ConnectionPool_start(internal);
}

void ZDB::ConnectionPool::stop() {
    ConnectionPool_stop(internal);
}

ZDB::Connection* ZDB::ConnectionPool::getConnection() {
  Connection_T connection;
    connection = ConnectionPool_getConnection(internal);
  return new ZDB::Connection(connection);
}

void ZDB::ConnectionPool::returnConnection(ZDB::Connection* connection) {
    ConnectionPool_returnConnection(internal, (Connection_T) connection->value());
  delete connection;
}

int ZDB::ConnectionPool::reapConnections() {
    RETURN ConnectionPool_reapConnections(internal);
}
