#ifndef DB_LEVELDB_H
#define DB_LEVELDB_H
#include <string>
#include <leveldb/db.h>
class DBLeveldb
{
public:
	DBLeveldb();
	~DBLeveldb();

	bool open(const std::string& db_path,bool create_if_missing = true);

	bool getData(const std::string& key, std::string& value) const;

	bool setData(const std::string& key, const std::string& value);

	bool delData(const std::string& key);

	void release();
private:
	leveldb::DB* db_;
	leveldb::Options options_;
};


#endif
