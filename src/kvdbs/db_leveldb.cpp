#include "kvdbs/db_leveldb.h"
DBLeveldb::DBLeveldb()
{
}
DBLeveldb::~DBLeveldb()
{
}
bool DBLeveldb::open(const std::string& db_path,bool create_if_missing /*= true*/)
{
	options_.create_if_missing = create_if_missing;
	leveldb::Status status = leveldb::DB::Open(options_,db_path,&db_);
	
	if ( !status.ok() )
		return false;
	return true;
}
bool DBLeveldb::getData(const std::string& key, std::string& value) const
{
	leveldb::Status status = db_->Get(leveldb::ReadOptions(),key, &value);
	if ( !status.ok() )
		return false;
	return true;
}
bool DBLeveldb::setData(const std::string& key, const std::string& value)
{
	leveldb::Status status = db_->Put(leveldb::WriteOptions(),key, value);

	if( !status.ok() )
		return false;
	return true;
}
bool DBLeveldb::delData(const std::string& key)
{
	leveldb::Status status = db_->Delete(leveldb::WriteOptions(), key);
	return true;
}
void DBLeveldb::release()
{
	delete db_;
}

