// 数据类型
// Created by 邦邦 on 2022/4/18.
#pragma once
#include <vector>
#include <array>
#include <string>
#include "ccore/safe/Log.h"

namespace bb {
    class dml_type {
    protected:
        std::vector<std::array<std::string, 6>> sql_arr_; //sql对象数组{key,"TINYINT类型","3长度","3精度","NOT NULL附加项","1是否redis索引"}
        std::vector<std::string> sql_other_; //特殊如INDEX (c2,c3)
    public:
        //小小整型-2^7 到 2^7-1(-128到127)，0到255 默认为4 大小1个字节
        dml_type *tinyint_(const std::string &key);

        dml_type *tinyint_(const std::string &key, const int &size);

        //小整型-2^15 到 2^15-1(-32768到32767)，0到65535 默认为6 大小2个字节
        dml_type *smallint_(const std::string &key);

        dml_type *smallint_(const std::string &key, const int &size);

        //中整型-8388608到8388607，0到16777215 默认为9 大小3个字节
        dml_type *mediumint_(const std::string &key);

        dml_type *mediumint_(const std::string &key, const int &size);

        //正常整型-2^31 到 2^31-1(-2147483648到2147483647)，0到4294967295 默认为11 大小4个字节
        dml_type *int_(const std::string &key);

        dml_type *int_(const std::string &key, const int &size);

        //长整型-2^63 到 2^63-1(-9223372036854775808到9223372036854775807)，0到18446744073709551615 默认为20 大小8个字节
        dml_type *bigint_(const std::string &key);

        dml_type *bigint_(const std::string &key, const int &size);

        //浮点型4,32bit数值范围为-3.4E38~3.4E38(7个有效位),左侧最大值占，21位，右侧最大值占4位，右侧超出4位会被截断
        dml_type *float_(const std::string &key);

        dml_type *float_(const std::string &key, const int &size);

        //precision精度
        dml_type *float_(const std::string &key, const int &size, const int &precision);

        //双精度型8,64bit数值范围-1.7E308~1.7E308(15个有效位)
        dml_type *double_(const std::string &key);

        dml_type *double_(const std::string &key, const int &size);

        dml_type *double_(const std::string &key, const int &size, const int &precision);

        //数字型128bit不存在精度损失，常用于银行帐目计算(28个有效位)
        dml_type *decimal_(const std::string &key);

        dml_type *decimal_(const std::string &key, const int &size);

        dml_type *decimal_(const std::string &key, const int &size, const int &precision);

        //字符串型 256 bytes
        dml_type *string_(const std::string &key);

        dml_type *string_(const std::string &key, const int &size);

        //文本类型 65,535 bytes
        dml_type *text_(const std::string &key);

        //日期值类型YYYY-MM-DD
        dml_type *date_(const std::string &key);
        //时间值或持续时间HH:MM:SS
        dml_type *time_(const std::string &key);
        //年份值YYYY
        dml_type *year_(const std::string &key);
        //混合日期和时间值YYYY-MM-DD HH:MM:SS
        dml_type *datetime_(const std::string &key);
        //混合日期和时间值，时间戳YYYYMMDD HHMMSS
        dml_type *timestamp_(const std::string &key);

        //创建时间+更新时间
        dml_type *dateAt_();

        //无符号的
        dml_type *unsigned_();

        //唯一的(不允许重复)
        dml_type *unique_();

        //允许为null
        dml_type *nullable_();

        //默认值
        dml_type *default_(const std::string &value);

        dml_type *default_(const int &value);

        //注解
        dml_type *comment_(const std::string &value);

        //填充0固定长度：123=0000000123
        dml_type *zerofill_();

        //设置索引 全文索引只支持char、varchar和text
        dml_type *index_(const std::vector<std::string> &key_list, const short &is_unique = 0);
        //普通索引
        dml_type *index_();
        //主键索引
        dml_type *indexPrimaryKey_();
        //全文索引
        dml_type *indexFulltext_();
        //唯一索引(只允许索引中的值对应一行，比如身份证号，而且当某个字段被指定为UNIQUE时会自动产生唯一索引)
        dml_type *indexUnique_();
        
        //设置非关系型数据索引
        dml_type *NoSQL_();
    };
}
