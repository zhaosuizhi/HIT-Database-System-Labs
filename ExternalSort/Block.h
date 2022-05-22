#pragma once

#include "Serializable.h"
#include "Record.h"

/// <summary>
/// 记录块，对应一个内存块
/// </summary>
class Block :public Serializable
{
public:
    /// <summary>
    /// 创建一个记录块
    /// </summary>
    /// <param name="size">块中的记录个数</param>
    Block(const size_t size);

    ~Block();

    /// <summary>
    /// 从流中读入记录块，返回读入的条数
    /// </summary>
    /// <param name="stream">输入流</param>
    /// <returns>读入记录的个数</returns>
    virtual int load(std::istream& stream) override;

    /// <summary>
    /// 将当前记录块输出到流中
    /// </summary>
    /// <param name="stream">输出流</param>
    /// <returns>输出成功返回0，失败返回-1</returns>
    virtual int dump(std::ostream& stream) override;
    
private:
    const size_t m_size;
    Record* m_record_array;
};

