#include <iostream>
#include "mysqlorm/mode/dbA1_test.hpp"

int main(int, char**) {
    //mysqlTestConn();
    dbA1_test::obj().insertF("'小明',24,1");
    dbA1_test::obj().where("id>0")->show();
    
    //dbA2_test::obj().where("id=2")->update("name:'aaa',age:1");·
    //dbA1_test::obj().select("name")->where("id='2dsaf' || id<\"2dsaf\" && id>=2 || id==2")->orWhere("id>2")->where("id=2 || id<2 && id>=2 || id==2")->show();
    /* dbA1_test::obj().insert("name:'aaa',age:1");
    dbA2_test::obj().insert("name:'bbb',age:1");
    auto db11 = dbA1_test::obj().select("name")->where("id>2");
    auto ad12 = dbA2_test::obj().select("name")->where("id>2");
    db11->show();
    ad12->show();
    
    dbA1_test::obj().selectArr({"id","name"})->where("id=4")->update("name:'aaa1',age:1");
    dbA2_test::obj().selectArr({"id","name"})->where("id=5")->update("name:'bbb1',age:2");
    */
    return 0;
}