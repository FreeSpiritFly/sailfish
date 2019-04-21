#include "kvdbs/db_rocksdb.h"
DBRocksdb::DBRocksdb()
{
}
DBRocksdb::~DBRocksdb()
{
}
bool DBRocksdb::open(const std::string& db_path,bool create_if_missing /*= true*/)
{
	options_.create_if_missing = create_if_missing;
	rocksdb::Status status = rocksdb::DB::Open(options_,db_path,&db_);
	
	if ( !status.ok() )
		return false;
	return true;
}
bool DBRocksdb::getData(const std::string& key, std::string& value) const
{
	rocksdb::Status status = db_->Get(rocksdb::ReadOptions(),key, &value);
	if ( !status.ok() )
		return false;
	return true;
}
bool DBRocksdb::setData(const std::string& key, const std::string& value)
{
	rocksdb::Status status = db_->Put(rocksdb::WriteOptions(),key, value);

	if( !status.ok() )
		return false;
	return true;
}
bool DBRocksdb::delData(const std::string& key)
{
	rocksdb::Status status = db_->Delete(rocksdb::WriteOptions(), key);
	return true;
}
void DBRocksdb::release()
{
	delete db_;
}

