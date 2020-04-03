#pragma once


struct source_location
{

private:
    using uint_least32_t = unsigned;
public:

    // 14.1.2, source_location creation
    static constexpr source_location  current(const char* __file = __FILE__, const char* __func = "dsds", int __line =__LINE__, int __col = 0) noexcept
    {
        source_location __loc;
        __loc._M_file = __file;
        __loc._M_func = __func;
        __loc._M_line = __line;
        __loc._M_col = __col;
        return __loc;
    }

    constexpr source_location() noexcept
        : _M_file("unknown"), _M_func(_M_file), _M_line(0), _M_col(0)
    { }

    // 14.1.3, source_location field access
    constexpr uint_least32_t line() const noexcept { return _M_line; }
    constexpr uint_least32_t column() const noexcept { return _M_col; }
    constexpr const char* file_name() const noexcept { return _M_file; }
    constexpr const char* function_name() const noexcept { return _M_func; }

private:
    const char* _M_file;
    const char* _M_func;
    uint_least32_t _M_line;
    uint_least32_t _M_col;
};

