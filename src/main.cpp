#include "kvdbs/db_leveldb.h"
#include <iostream>
int main(int argc, char* argv[])
{
	std::string db_path = "./data";
	DBLeveldb db;
	db.open(db_path);
	std::string pre_value;
	db.getData("Key",pre_value);
	std::cout << "pre data: " << pre_value << std::endl;
	//db.setData("Key", "Value1");
	std::string value ;
	db.getData("Key", value);
	std::cout << "data is: " << value << std::endl;
	db.release();
	return 0;
}
