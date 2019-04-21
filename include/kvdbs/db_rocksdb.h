#ifndef DB_ROCKSDB_H
#define DB_ROCKSDB_H
#include <string>
#include <rocksdb/db.h>
class DBRocksdb
{
public:
	DBRocksdb();
	~DBRocksdb();

	bool open(const std::string& db_path,bool create_if_missing = true);

	bool getData(const std::string& key, std::string& value) const;

	bool setData(const std::string& key, const std::string& value);

	bool delData(const std::string& key);

	void release();
private:
	rocksdb::DB* db_;
	rocksdb::Options options_;
};


#endif
