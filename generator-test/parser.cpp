#include "parser.hpp"
#include <iostream>

 leaf::parsing::instance::resetable::resetable(instance& ref): m_ref(ref)
{
    m_contents = ref.m_contents;
    m_file = ref.m_file;
    m_line = ref.m_line;
    m_column = ref.m_column;
    m_offset = ref.m_offset;
}
void leaf::parsing::instance::resetable::reset()
{
    m_ref.m_contents   = m_contents;
    m_ref.m_file       = m_file;
    m_ref.m_line       = m_line;
    m_ref.m_column     = m_column;
    m_ref.m_offset     = m_offset;
}
bool leaf::parsing::instance::next()
{
    if (m_contents.length() > m_offset)
    {
        char c = m_contents[m_offset];
        switch (c)
        {
            case '\r':
            case '\t':
            case ' ':
            default: m_column++; m_offset++; break;
            case '\n': m_line++; m_column = 1; m_offset++; break;
        }
        return true;
    }
    else
    {
        return false;
    }
}
char leaf::parsing::instance::current()
{
    if (m_contents.length() > m_offset)
    {
        return m_contents[m_offset];
    }
    else
    {
        return '\0';
    }
}
std::optional<size_t> leaf::parsing::instance::token_integer_binary(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "0b";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0')
    {
        if (('0' <= current() && current() <= '9'))
        {
            count4++;
            next();
            continue;
        }
        std::optional<size_t> res5 = token_underscore(depth + 1);
        if (res5.has_value())
        {
            count4++;
            for (size_t i = 0; i < res5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable1 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable1;
}
std::optional<size_t> leaf::parsing::instance::token_integer_hex(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "0x";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0')
    {
        if (('0' <= current() && current() <= '9'))
        {
            count4++;
            next();
            continue;
        }
        std::optional<size_t> res5 = token_underscore(depth + 1);
        if (res5.has_value())
        {
            count4++;
            for (size_t i = 0; i < res5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable2 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable2;
}
std::optional<size_t> leaf::parsing::instance::token_integer_unsigned(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0')
    {
        if (('0' <= current() && current() <= '9'))
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable3 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable3;
}
std::optional<size_t> leaf::parsing::instance::token_integer_signed_negative(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '-')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        if (('0' <= current() && current() <= '9'))
        {
            count3++;
            next();
            continue;
        }
        break;
    }
    if (count3 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable4 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable4;
}
std::optional<size_t> leaf::parsing::instance::token_integer_signed_positive(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '+')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        if (('0' <= current() && current() <= '9'))
        {
            count3++;
            next();
            continue;
        }
        break;
    }
    if (count3 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable5 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable5;
}
std::optional<size_t> leaf::parsing::instance::token_integer(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        std::optional<size_t> res3 = token_integer_signed_positive(depth + 1);
        if (res3.has_value())
        {
            count2++;
            for (size_t i = 0; i < res3; i++)
            {
                next();
            }
            continue;
        }
        std::optional<size_t> res4 = token_integer_signed_negative(depth + 1);
        if (res4.has_value())
        {
            count2++;
            for (size_t i = 0; i < res4; i++)
            {
                next();
            }
            continue;
        }
        std::optional<size_t> res5 = token_integer_unsigned(depth + 1);
        if (res5.has_value())
        {
            count2++;
            for (size_t i = 0; i < res5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable6 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable6;
}
std::optional<size_t> leaf::parsing::instance::token_scalar(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        std::optional<size_t> res3 = token_integer(depth + 1);
        if (res3.has_value())
        {
            count2++;
            for (size_t i = 0; i < res3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0' && count4 < 1)
    {
        if (current() == '.')
        {
            count4++;
            next();
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count5 = 0;
    while (current() != '\0' && count5 < 1)
    {
        std::optional<size_t> res6 = token_integer(depth + 1);
        if (res6.has_value())
        {
            count5++;
            for (size_t i = 0; i < res6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count5 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable7 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable7;
}
std::optional<size_t> leaf::parsing::instance::token_slash(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '/')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable8 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable8;
}
std::optional<size_t> leaf::parsing::instance::token_star(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '*')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable9 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable9;
}
std::optional<size_t> leaf::parsing::instance::token_plus(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '+')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable10 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable10;
}
std::optional<size_t> leaf::parsing::instance::token_minus(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '-')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable11 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable11;
}
std::optional<size_t> leaf::parsing::instance::token_underscore(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '_')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable12 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable12;
}
std::optional<size_t> leaf::parsing::instance::token_true_(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "true";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable13 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable13;
}
std::optional<size_t> leaf::parsing::instance::token_false_(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "false";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable14 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable14;
}
std::optional<size_t> leaf::parsing::instance::token_ident(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (('a' <= current() && current() <= 'z'))
        {
            count2++;
            next();
            continue;
        }
        else if (('A' <= current() && current() <= 'Z'))
        {
            count2++;
            next();
            continue;
        }
        std::optional<size_t> res3 = token_underscore(depth + 1);
        if (res3.has_value())
        {
            count2++;
            for (size_t i = 0; i < res3; i++)
            {
                next();
            }
            continue;
        }
        std::optional<size_t> res4 = token_minus(depth + 1);
        if (res4.has_value())
        {
            count2++;
            for (size_t i = 0; i < res4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count5 = 0;
    while (current() != '\0')
    {
        if (('a' <= current() && current() <= 'z'))
        {
            count5++;
            next();
            continue;
        }
        else if (('A' <= current() && current() <= 'Z'))
        {
            count5++;
            next();
            continue;
        }
        else if (('0' <= current() && current() <= '9'))
        {
            count5++;
            next();
            continue;
        }
        std::optional<size_t> res6 = token_underscore(depth + 1);
        if (res6.has_value())
        {
            count5++;
            for (size_t i = 0; i < res6; i++)
            {
                next();
            }
            continue;
        }
        std::optional<size_t> res7 = token_minus(depth + 1);
        if (res7.has_value())
        {
            count5++;
            for (size_t i = 0; i < res7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    size_t count8 = 1;
    size_t loff9 = 0;
    while (current() != '\0' && count8 > 0)
    {
        if (m_offset >= 1 && m_contents[m_offset - 1] == '-')
        {
            break;
        }
        count8--;
    }
    if (count8 >= 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable15 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable15;
}
std::optional<size_t> leaf::parsing::instance::token_string_formatable_start(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '$')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0' && count3 < 1)
    {
        if (current() == '\"')
        {
            count3++;
            next();
            continue;
        }
        break;
    }
    if (count3 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0')
    {
        if (current() != '{')
        {
            count4++;
            next();
            continue;
        }
        break;
    }
    size_t count5 = 0;
    while (current() != '\0' && count5 < 1)
    {
        if (current() == '{')
        {
            count5++;
            next();
            continue;
        }
        break;
    }
    if (count5 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable16 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable16;
}
std::optional<size_t> leaf::parsing::instance::token_string_formatable_fake(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '$')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0' && count3 < 1)
    {
        if (current() == '\"')
        {
            count3++;
            next();
            continue;
        }
        break;
    }
    if (count3 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0')
    {
        std::optional<size_t> res5 = token_string_unescaped_ending(depth + 1);
        if (res5.has_value())
        {
            count4++;
            for (size_t i = 0; i < res5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    size_t count6 = 0;
    while (current() != '\0' && count6 < 1)
    {
        if (current() == '\"')
        {
            count6++;
            next();
            continue;
        }
        break;
    }
    if (count6 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable17 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable17;
}
std::optional<size_t> leaf::parsing::instance::token_string_formatable_continuation(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '}')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        if (current() != '{')
        {
            count3++;
            next();
            continue;
        }
        break;
    }
    size_t count4 = 0;
    while (current() != '\0' && count4 < 1)
    {
        if (current() == '{')
        {
            count4++;
            next();
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable18 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable18;
}
std::optional<size_t> leaf::parsing::instance::token_string_formatable_end(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '}')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        std::optional<size_t> res4 = token_string_unescaped_ending(depth + 1);
        if (res4.has_value())
        {
            count3++;
            for (size_t i = 0; i < res4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    size_t count5 = 0;
    while (current() != '\0' && count5 < 1)
    {
        if (current() == '\"')
        {
            count5++;
            next();
            continue;
        }
        break;
    }
    if (count5 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable19 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable19;
}
std::optional<size_t> leaf::parsing::instance::token_string_unescaped_ending(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 1;
    size_t loff3 = 0;
    while (current() != '\0' && count2 > 0)
    {
        if (m_offset >= 1 && m_contents[m_offset - 1] == '\')
        {
            break;
        }
        count2--;
    }
    if (count2 >= 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0' && count4 < 1)
    {
        if (current() == '\"')
        {
            count4++;
            next();
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable20 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable20;
}
std::optional<size_t> leaf::parsing::instance::token_string(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '\"')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        std::optional<size_t> res4 = token_string_unescaped_ending(depth + 1);
        if (res4.has_value())
        {
            count3++;
            for (size_t i = 0; i < res4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    size_t count5 = 0;
    while (current() != '\0' && count5 < 1)
    {
        if (current() == '\"')
        {
            count5++;
            next();
            continue;
        }
        break;
    }
    if (count5 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable21 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable21;
}
std::optional<size_t> leaf::parsing::instance::token_char_unescaped_ending(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 1;
    size_t loff3 = 0;
    while (current() != '\0' && count2 > 0)
    {
        if (m_offset >= 1 && m_contents[m_offset - 1] == '\')
        {
            break;
        }
        count2--;
    }
    if (count2 >= 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count4 = 0;
    while (current() != '\0' && count4 < 1)
    {
        if (current() == '\'')
        {
            count4++;
            next();
            continue;
        }
        break;
    }
    if (count4 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable22 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable22;
}
std::optional<size_t> leaf::parsing::instance::token_char_(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '\'')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    size_t count3 = 0;
    while (current() != '\0')
    {
        std::optional<size_t> res4 = token_char_unescaped_ending(depth + 1);
        if (res4.has_value())
        {
            count3++;
            for (size_t i = 0; i < res4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    size_t count5 = 0;
    while (current() != '\0' && count5 < 1)
    {
        if (current() == '\'')
        {
            count5++;
            next();
            continue;
        }
        break;
    }
    if (count5 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable23 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable23;
}
std::optional<size_t> leaf::parsing::instance::token__colon(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == ':')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable24 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable24;
}
std::optional<size_t> leaf::parsing::instance::token__comma(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == ',')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable25 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable25;
}
std::optional<size_t> leaf::parsing::instance::token__round_bracked_open(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '(')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable26 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable26;
}
std::optional<size_t> leaf::parsing::instance::token__round_bracked_close(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == ')')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable27 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable27;
}
std::optional<size_t> leaf::parsing::instance::token__square_bracked_open(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '[')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable28 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable28;
}
std::optional<size_t> leaf::parsing::instance::token__square_bracked_close(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == ']')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable29 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable29;
}
std::optional<size_t> leaf::parsing::instance::token__curly_bracked_open(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '{')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable30 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable30;
}
std::optional<size_t> leaf::parsing::instance::token__curly_bracked_close(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '}')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable31 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable31;
}
std::optional<size_t> leaf::parsing::instance::token__get(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "get";
        if (m_contents.length() - m_offset >= 3 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 3, str3, str3 + 3))
        {
            count2++;
            for (size_t i = 0; i < 3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable32 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable32;
}
std::optional<size_t> leaf::parsing::instance::token__set(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "set";
        if (m_contents.length() - m_offset >= 3 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 3, str3, str3 + 3))
        {
            count2++;
            for (size_t i = 0; i < 3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable33 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable33;
}
std::optional<size_t> leaf::parsing::instance::token__while(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "while";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable34 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable34;
}
std::optional<size_t> leaf::parsing::instance::token__if(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "if";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable35 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable35;
}
std::optional<size_t> leaf::parsing::instance::token__else(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "else";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable36 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable36;
}
std::optional<size_t> leaf::parsing::instance::token__case(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "case";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable37 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable37;
}
std::optional<size_t> leaf::parsing::instance::token__switch(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "switch";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable38 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable38;
}
std::optional<size_t> leaf::parsing::instance::token__default(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "default";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable39 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable39;
}
std::optional<size_t> leaf::parsing::instance::token__eol(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '\n')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable40 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable40;
}
std::optional<size_t> leaf::parsing::instance::token__assembly(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "assembly";
        if (m_contents.length() - m_offset >= 8 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 8, str3, str3 + 8))
        {
            count2++;
            for (size_t i = 0; i < 8; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable41 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable41;
}
std::optional<size_t> leaf::parsing::instance::token__dot(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '.')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable42 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable42;
}
std::optional<size_t> leaf::parsing::instance::token__exclamation(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '!')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable43 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable43;
}
std::optional<size_t> leaf::parsing::instance::token__tilde(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '~')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable44 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable44;
}
std::optional<size_t> leaf::parsing::instance::token__less_then_less_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "<<";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable45 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable45;
}
std::optional<size_t> leaf::parsing::instance::token__greater_then_greater_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = ">>";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable46 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable46;
}
std::optional<size_t> leaf::parsing::instance::token__less_then_less_then_less_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "<<<";
        if (m_contents.length() - m_offset >= 3 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 3, str3, str3 + 3))
        {
            count2++;
            for (size_t i = 0; i < 3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable47 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable47;
}
std::optional<size_t> leaf::parsing::instance::token__greater_then_greater_then_greater_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = ">>>";
        if (m_contents.length() - m_offset >= 3 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 3, str3, str3 + 3))
        {
            count2++;
            for (size_t i = 0; i < 3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable48 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable48;
}
std::optional<size_t> leaf::parsing::instance::token__ampersand(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '&')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable49 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable49;
}
std::optional<size_t> leaf::parsing::instance::token__circumflex(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '^')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable50 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable50;
}
std::optional<size_t> leaf::parsing::instance::token__vertical_bar(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '|')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable51 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable51;
}
std::optional<size_t> leaf::parsing::instance::token__less_then_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "<=";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable52 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable52;
}
std::optional<size_t> leaf::parsing::instance::token__less_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '<')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable53 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable53;
}
std::optional<size_t> leaf::parsing::instance::token__greater_then_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = ">=";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable54 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable54;
}
std::optional<size_t> leaf::parsing::instance::token__greater_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '>')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable55 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable55;
}
std::optional<size_t> leaf::parsing::instance::token__exclamation_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "!=";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable56 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable56;
}
std::optional<size_t> leaf::parsing::instance::token__equal_equal_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "===";
        if (m_contents.length() - m_offset >= 3 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 3, str3, str3 + 3))
        {
            count2++;
            for (size_t i = 0; i < 3; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable57 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable57;
}
std::optional<size_t> leaf::parsing::instance::token__equal_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "==";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable58 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable58;
}
std::optional<size_t> leaf::parsing::instance::token__tilde_equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "~=";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable59 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable59;
}
std::optional<size_t> leaf::parsing::instance::token__ampersand_ampersand(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "&&";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable60 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable60;
}
std::optional<size_t> leaf::parsing::instance::token__vertical_bar_vertical_bar(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "||";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable61 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable61;
}
std::optional<size_t> leaf::parsing::instance::token__equal(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == '=')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable62 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable62;
}
std::optional<size_t> leaf::parsing::instance::token__public(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "public";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable63 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable63;
}
std::optional<size_t> leaf::parsing::instance::token__local(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "local";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable64 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable64;
}
std::optional<size_t> leaf::parsing::instance::token__derived(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "derived";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable65 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable65;
}
std::optional<size_t> leaf::parsing::instance::token__private(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "private";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable66 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable66;
}
std::optional<size_t> leaf::parsing::instance::token__namespace(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "namespace";
        if (m_contents.length() - m_offset >= 9 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 9, str3, str3 + 9))
        {
            count2++;
            for (size_t i = 0; i < 9; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable67 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable67;
}
std::optional<size_t> leaf::parsing::instance::token__class(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "class";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable68 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable68;
}
std::optional<size_t> leaf::parsing::instance::token__sealed(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "sealed";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable69 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable69;
}
std::optional<size_t> leaf::parsing::instance::token__virtual(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "virtual";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable70 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable70;
}
std::optional<size_t> leaf::parsing::instance::token__unbound(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "unbound";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable71 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable71;
}
std::optional<size_t> leaf::parsing::instance::token__inline(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "inline";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable72 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable72;
}
std::optional<size_t> leaf::parsing::instance::token__delete(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "delete";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable73 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable73;
}
std::optional<size_t> leaf::parsing::instance::token__conversion(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "conversion";
        if (m_contents.length() - m_offset >= 10 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 10, str3, str3 + 10))
        {
            count2++;
            for (size_t i = 0; i < 10; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable74 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable74;
}
std::optional<size_t> leaf::parsing::instance::token__operator(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "operator";
        if (m_contents.length() - m_offset >= 8 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 8, str3, str3 + 8))
        {
            count2++;
            for (size_t i = 0; i < 8; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable75 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable75;
}
std::optional<size_t> leaf::parsing::instance::token__semicolon(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        if (current() == ';')
        {
            count2++;
            next();
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable76 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable76;
}
std::optional<size_t> leaf::parsing::instance::token__using(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "using";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable77 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable77;
}
std::optional<size_t> leaf::parsing::instance::token__free(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "free";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable78 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable78;
}
std::optional<size_t> leaf::parsing::instance::token__alloc(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "alloc";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable79 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable79;
}
std::optional<size_t> leaf::parsing::instance::token__stack(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "stack";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable80 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable80;
}
std::optional<size_t> leaf::parsing::instance::token__heap(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "heap";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable81 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable81;
}
std::optional<size_t> leaf::parsing::instance::token__typeof(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "typeof";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable82 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable82;
}
std::optional<size_t> leaf::parsing::instance::token__nameof(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "nameof";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable83 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable83;
}
std::optional<size_t> leaf::parsing::instance::token__sizeof(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "sizeof";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable84 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable84;
}
std::optional<size_t> leaf::parsing::instance::token__return(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "return";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable85 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable85;
}
std::optional<size_t> leaf::parsing::instance::token__auto_626(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "<!pragma";
        if (m_contents.length() - m_offset >= 8 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 8, str3, str3 + 8))
        {
            count2++;
            for (size_t i = 0; i < 8; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable86 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable86;
}
std::optional<size_t> leaf::parsing::instance::token__exclamation_greater_then(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "!>";
        if (m_contents.length() - m_offset >= 2 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 2, str3, str3 + 2))
        {
            count2++;
            for (size_t i = 0; i < 2; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable87 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable87;
}
std::optional<size_t> leaf::parsing::instance::token__align(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "align";
        if (m_contents.length() - m_offset >= 5 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 5, str3, str3 + 5))
        {
            count2++;
            for (size_t i = 0; i < 5; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable88 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable88;
}
std::optional<size_t> leaf::parsing::instance::token__size(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "size";
        if (m_contents.length() - m_offset >= 4 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 4, str3, str3 + 4))
        {
            count2++;
            for (size_t i = 0; i < 4; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable89 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable89;
}
std::optional<size_t> leaf::parsing::instance::token__disable(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "disable";
        if (m_contents.length() - m_offset >= 7 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 7, str3, str3 + 7))
        {
            count2++;
            for (size_t i = 0; i < 7; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable90 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable90;
}
std::optional<size_t> leaf::parsing::instance::token__enable(size_t depth)
{
    resetable resetable1(*this);
    size_t count2 = 0;
    while (current() != '\0' && count2 < 1)
    {
        const char* str3 = "enable";
        if (m_contents.length() - m_offset >= 6 && std::equal(m_contents.begin() + m_offset, m_contents.begin() + m_offset + 6, str3, str3 + 6))
        {
            count2++;
            for (size_t i = 0; i < 6; i++)
            {
                next();
            }
            continue;
        }
        break;
    }
    if (count2 < 1)
    {
        resetable1.reset();
        return {};
    }
    auto resultVariable91 = m_offset - resetable1.m_offset;
    resetable1.reset();
    return resultVariable91;
}
bool leaf::parsing::instance::m_expor_92(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a>& actual, leaf::parsing::instance::attribute_arg_item_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_or(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_or(depth + 1);
    actual->value = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_attribute_arg_item_a(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a> fake;
    attribute_arg_item_a_state state;
    if (!m_expor_92(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a> leaf::parsing::instance::p_match_attribute_arg_item_a(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute_arg_item_a>();
    std::shared_ptr<leaf::parsing::instance::attribute_arg_item_a> fake;
    attribute_arg_item_a_state state;
    resetable resetable2(*this);
    if (m_expor_92(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_expor_92(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_colon_expor_93(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b>& actual, leaf::parsing::instance::attribute_arg_item_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__colon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_or(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val6;
    skip();
    auto l8 = token__colon(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = lr_match_exp_or(depth + 1);
    actual->value = val9;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_attribute_arg_item_b(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b> fake;
    attribute_arg_item_b_state state;
    if (!m_ident_colon_expor_93(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b> leaf::parsing::instance::p_match_attribute_arg_item_b(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute_arg_item_b>();
    std::shared_ptr<leaf::parsing::instance::attribute_arg_item_b> fake;
    attribute_arg_item_b_state state;
    resetable resetable2(*this);
    if (m_ident_colon_expor_93(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_ident_colon_expor_93(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attributeargitema_94(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_arg_item_a(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute_arg_item_a(depth + 1);
    actual->args.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attributeargitema_95(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_arg_item_a(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute_arg_item_a(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_attributeargitema_96(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_arg_item_a(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_attribute_arg_item_a(depth + 1);
    actual->args.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::while97_98(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attributeargitema_95(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeargitema_96(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-arg-item-a (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeargitema_95(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeargitema_96(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-arg-item-a (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeargitema_95(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_comma_99(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_100(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if101_102(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_a>& actual, leaf::parsing::instance::attribute_args_a_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_comma_99(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_comma_100(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_comma_100(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_attribute_args_a(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute_args_a> fake;
    attribute_args_a_state state;
    if (!m_attributeargitema_94(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while97_98(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if101_102(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute_args_a> leaf::parsing::instance::p_match_attribute_args_a(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute_args_a>();
    std::shared_ptr<leaf::parsing::instance::attribute_args_a> fake;
    attribute_args_a_state state;
    resetable resetable2(*this);
    if (m_attributeargitema_94(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_attributeargitema_94(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while97_98(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while97_98(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if101_102(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if101_102(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attributeargitemb_103(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_arg_item_b(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute_arg_item_b(depth + 1);
    actual->args.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attributeargitemb_104(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_arg_item_b(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute_arg_item_b(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_attributeargitemb_105(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_arg_item_b(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_attribute_arg_item_b(depth + 1);
    actual->args.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::while106_107(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attributeargitemb_104(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeargitemb_105(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-arg-item-b (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeargitemb_104(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeargitemb_105(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-arg-item-b (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeargitemb_104(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_comma_108(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_109(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if110_111(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_args_b>& actual, leaf::parsing::instance::attribute_args_b_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_comma_108(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_comma_109(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_comma_109(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_attribute_args_b(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute_args_b> fake;
    attribute_args_b_state state;
    if (!m_attributeargitemb_103(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while106_107(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if110_111(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute_args_b> leaf::parsing::instance::p_match_attribute_args_b(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute_args_b>();
    std::shared_ptr<leaf::parsing::instance::attribute_args_b> fake;
    attribute_args_b_state state;
    resetable resetable2(*this);
    if (m_attributeargitemb_103(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_attributeargitemb_103(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while106_107(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while106_107(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if110_111(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if110_111(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_typematch_112(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_type_match(depth + 1);
    actual->target_type = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_typematch_roundbrackedopen_roundbrackedclose_113(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_type_match(depth + 1);
    actual->target_type = val6;
    skip();
    auto l8 = token__round_bracked_open(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_typematch_roundbrackedopen_attributeargsa_attributeargsb_roundbrackedclose_114(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_args_a(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_args_b(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_type_match(depth + 1);
    actual->target_type = val6;
    skip();
    auto l8 = token__round_bracked_open(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = p_match_attribute_args_a(depth + 1);
    actual->args = val9;
    skip();
    p_match_attribute_args_b(depth + 1);
    skip();
    auto l12 = token__round_bracked_close(depth + 1).value();
    for (;l12 != 0; l12--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_typematch_roundbrackedopen_attributeargsa_roundbrackedclose_115(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_args_a(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_type_match(depth + 1);
    actual->target_type = val6;
    skip();
    auto l8 = token__round_bracked_open(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = p_match_attribute_args_a(depth + 1);
    actual->args = val9;
    skip();
    auto l11 = token__round_bracked_close(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_typematch_roundbrackedopen_attributeargsb_roundbrackedclose_116(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_args_b(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_type_match(depth + 1);
    actual->target_type = val6;
    skip();
    auto l8 = token__round_bracked_open(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = p_match_attribute_args_b(depth + 1);
    actual->args = val9;
    skip();
    auto l11 = token__round_bracked_close(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives117(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute_item>& actual, leaf::parsing::instance::attribute_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_typematch_112(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typematch_112(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typematch_roundbrackedopen_roundbrackedclose_113(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typematch_roundbrackedopen_roundbrackedclose_113(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typematch_roundbrackedopen_attributeargsa_attributeargsb_roundbrackedclose_114(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typematch_roundbrackedopen_attributeargsa_attributeargsb_roundbrackedclose_114(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typematch_roundbrackedopen_attributeargsa_roundbrackedclose_115(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typematch_roundbrackedopen_attributeargsa_roundbrackedclose_115(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typematch_roundbrackedopen_attributeargsb_roundbrackedclose_116(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typematch_roundbrackedopen_attributeargsb_roundbrackedclose_116(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_attribute_item(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute_item> fake;
    attribute_item_state state;
    if (!alternatives117(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute_item> leaf::parsing::instance::p_match_attribute_item(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute_item>();
    std::shared_ptr<leaf::parsing::instance::attribute_item> fake;
    attribute_item_state state;
    resetable resetable2(*this);
    if (alternatives117(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives117(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_squarebrackedopen_118(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__square_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_attributeitem_119(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute_item(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attributeitem_120(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute_item(depth + 1);
    actual->items.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attributeitem_121(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute_item(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_attributeitem_122(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_attribute_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_attribute_item(depth + 1);
    actual->items.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::while123_124(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attributeitem_121(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeitem_122(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-item (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeitem_121(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_comma_attributeitem_122(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}), $ref: attribute-item (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attributeitem_121(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_comma_125(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_126(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if127_128(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_comma_125(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_comma_126(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_comma_126(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::if129_130(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_attributeitem_119(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_attributeitem_120(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute-item (XCG.Parsing.Production) }", depth);
                return false;
            }
            while123_124(true, actual, state, depth + 1);
            if127_128(true, actual, state, depth + 1);
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_attributeitem_120(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute-item (XCG.Parsing.Production) }", depth);
                return false;
            }
            while123_124(false, actual, state, depth + 1);
            if127_128(false, actual, state, depth + 1);
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_squarebrackedclose_131(bool is_can, std::shared_ptr<leaf::parsing::instance::attribute>& actual, leaf::parsing::instance::attribute_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__square_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_attribute(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::attribute> fake;
    attribute_state state;
    if (!m_squarebrackedopen_118(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if129_130(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_squarebrackedclose_131(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::attribute> leaf::parsing::instance::p_match_attribute(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::attribute>();
    std::shared_ptr<leaf::parsing::instance::attribute> fake;
    attribute_state state;
    resetable resetable2(*this);
    if (m_squarebrackedopen_118(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_squarebrackedopen_118(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (if129_130(true, fake, state, depth + 1))
    {
        resetable3.reset();
        if129_130(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_squarebrackedclose_131(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_squarebrackedclose_131(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_curlybrackedopen_132(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_133(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_using_134(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_using_(depth + 1);
    actual->usings.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_controlstructure_135(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_control_structure(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_control_structure(depth + 1);
    actual->body.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_statement_136(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_statement(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_statement(depth + 1);
    actual->body.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives137(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_using_134(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_using_134(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_controlstructure_135(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_controlstructure_135(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_statement_136(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_statement_136(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { using, control-structure, statement }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while138_139(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_curlybrackedclose_133(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives137(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_133(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives137(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives137(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_133(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_curlybrackedclose_140(bool is_can, std::shared_ptr<leaf::parsing::instance::scope>& actual, leaf::parsing::instance::scope_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_scope(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::scope> fake;
    scope_state state;
    if (!m_curlybrackedopen_132(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while138_139(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_140(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::scope> leaf::parsing::instance::p_match_scope(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::scope>();
    std::shared_ptr<leaf::parsing::instance::scope> fake;
    scope_state state;
    resetable resetable2(*this);
    if (m_curlybrackedopen_132(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_curlybrackedopen_132(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while138_139(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while138_139(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_curlybrackedclose_140(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_curlybrackedclose_140(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_curlybrackedopen_141(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_get_scope_set_scope_142(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__get(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__set(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__get(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_scope(depth + 1);
    actual->get = val8;
    skip();
    auto l10 = token__set(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto val11 = p_match_scope(depth + 1);
    actual->set = val11;
    skip();
    return true;
}
bool leaf::parsing::instance::m_set_scope_get_scope_143(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__set(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__get(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__set(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_scope(depth + 1);
    actual->set = val8;
    skip();
    auto l10 = token__get(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto val11 = p_match_scope(depth + 1);
    actual->get = val11;
    skip();
    return true;
}
bool leaf::parsing::instance::m_get_scope_144(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__get(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__get(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_scope(depth + 1);
    actual->get = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::m_set_scope_145(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__set(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__set(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_scope(depth + 1);
    actual->set = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives146(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_get_scope_set_scope_142(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_get_scope_set_scope_142(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_set_scope_get_scope_143(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_set_scope_get_scope_143(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_get_scope_144(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_get_scope_144(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_set_scope_145(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_set_scope_145(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::m_curlybrackedclose_147(bool is_can, std::shared_ptr<leaf::parsing::instance::scope_getset>& actual, leaf::parsing::instance::scope_getset_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_scope_getset(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::scope_getset> fake;
    scope_getset_state state;
    if (!m_curlybrackedopen_141(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives146(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_147(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::scope_getset> leaf::parsing::instance::p_match_scope_getset(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::scope_getset>();
    std::shared_ptr<leaf::parsing::instance::scope_getset> fake;
    scope_getset_state state;
    resetable resetable2(*this);
    if (m_curlybrackedopen_141(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_curlybrackedopen_141(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (alternatives146(true, fake, state, depth + 1))
    {
        resetable3.reset();
        alternatives146(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_curlybrackedclose_147(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_curlybrackedclose_147(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_scope_148(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_controlstructure_149(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_control_structure(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_control_structure(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_statement_150(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_statement(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_statement(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives151(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure_body>& actual, leaf::parsing::instance::control_structure_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_scope_148(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scope_148(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_controlstructure_149(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_controlstructure_149(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_statement_150(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_statement_150(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_control_structure_body(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::control_structure_body> fake;
    control_structure_body_state state;
    if (!alternatives151(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::control_structure_body> leaf::parsing::instance::p_match_control_structure_body(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::control_structure_body>();
    std::shared_ptr<leaf::parsing::instance::control_structure_body> fake;
    control_structure_body_state state;
    resetable resetable2(*this);
    if (alternatives151(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives151(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_while_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_152(bool is_can, std::shared_ptr<leaf::parsing::instance::while_loop>& actual, leaf::parsing::instance::while_loop_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__while(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_control_structure_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__while(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = p_match_expression(depth + 1);
    actual->condition = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    auto val15 = p_match_control_structure_body(depth + 1);
    actual->body = val15;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_while_loop(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::while_loop> fake;
    while_loop_state state;
    if (!m_while_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_152(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::while_loop> leaf::parsing::instance::p_match_while_loop(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::while_loop>();
    std::shared_ptr<leaf::parsing::instance::while_loop> fake;
    while_loop_state state;
    resetable resetable2(*this);
    if (m_while_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_152(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_while_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_152(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_if_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_153(bool is_can, std::shared_ptr<leaf::parsing::instance::if_body>& actual, leaf::parsing::instance::if_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__if(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_control_structure_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__if(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = p_match_expression(depth + 1);
    actual->condition = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    auto val15 = p_match_control_structure_body(depth + 1);
    actual->body = val15;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_if_body(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::if_body> fake;
    if_body_state state;
    if (!m_if_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_153(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::if_body> leaf::parsing::instance::p_match_if_body(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::if_body>();
    std::shared_ptr<leaf::parsing::instance::if_body> fake;
    if_body_state state;
    resetable resetable2(*this);
    if (m_if_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_153(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_if_roundbrackedopen_expression_roundbrackedclose_controlstructurebody_153(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_else_controlstructurebody_154(bool is_can, std::shared_ptr<leaf::parsing::instance::else_body>& actual, leaf::parsing::instance::else_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__else(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_control_structure_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__else(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_control_structure_body(depth + 1);
    actual->else_body = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_else_body(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::else_body> fake;
    else_body_state state;
    if (!m_else_controlstructurebody_154(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::else_body> leaf::parsing::instance::p_match_else_body(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::else_body>();
    std::shared_ptr<leaf::parsing::instance::else_body> fake;
    else_body_state state;
    resetable resetable2(*this);
    if (m_else_controlstructurebody_154(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_else_controlstructurebody_154(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ifbody_155(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_if_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_if_body(depth + 1);
    actual->if_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_elsebody_156(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_else_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_else_body(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_elsebody_157(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_else_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_else_body(depth + 1);
    actual->else_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if158_159(bool is_can, std::shared_ptr<leaf::parsing::instance::if_else>& actual, leaf::parsing::instance::if_else_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_elsebody_156(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_elsebody_157(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: else-body (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_elsebody_157(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: else-body (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_if_else(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::if_else> fake;
    if_else_state state;
    if (!m_ifbody_155(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if158_159(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::if_else> leaf::parsing::instance::p_match_if_else(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::if_else>();
    std::shared_ptr<leaf::parsing::instance::if_else> fake;
    if_else_state state;
    resetable resetable2(*this);
    if (m_ifbody_155(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_ifbody_155(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (if158_159(true, fake, state, depth + 1))
    {
        resetable3.reset();
        if158_159(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_case_expvalue_colon_controlstructurebody_160(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_case>& actual, leaf::parsing::instance::switch_case_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__case(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_value(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__colon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_control_structure_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__case(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_exp_value(depth + 1);
    actual->value = val8;
    skip();
    auto l10 = token__colon(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto val11 = p_match_control_structure_body(depth + 1);
    actual->body = val11;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_switch_case(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::switch_case> fake;
    switch_case_state state;
    if (!m_case_expvalue_colon_controlstructurebody_160(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::switch_case> leaf::parsing::instance::p_match_switch_case(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::switch_case>();
    std::shared_ptr<leaf::parsing::instance::switch_case> fake;
    switch_case_state state;
    resetable resetable2(*this);
    if (m_case_expvalue_colon_controlstructurebody_160(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_case_expvalue_colon_controlstructurebody_160(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_switch_roundbrackedopen_expression_roundbrackedclose_161(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__switch(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__switch(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = p_match_expression(depth + 1);
    actual->value = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_162(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_switchcase_163(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_switch_case(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_switch_case(depth + 1);
    actual->part.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::if164_165(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = state.has_default.value();
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            report(" Multiple default cases found
", depth);
            return true;
        }
        else
        {
            if (!is_can)
            {
                state.has_default = true;
            }
            return true;
        }
    }
    else
    {
        if (cond2)
        {
            report(" Multiple default cases found
", depth);
            return true;
        }
        else
        {
            if (!is_can)
            {
                state.has_default = true;
            }
            return true;
        }
    }
}
bool leaf::parsing::instance::m_default_colon_controlstructurebody_166(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__default(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__colon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_control_structure_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__default(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto l9 = token__colon(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto val10 = p_match_control_structure_body(depth + 1);
    actual->default_body.push_back(val10);
    skip();
    if164_165(false, actual, state, depth + 1);
    return true;
}
bool leaf::parsing::instance::m_pragma_167(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragmas.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives168(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_switchcase_163(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_switchcase_163(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_default_colon_controlstructurebody_166(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_default_colon_controlstructurebody_166(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragma_167(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_167(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { switch-case, default, :, control-structure-body, pragma }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while169_170(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_curlybrackedclose_162(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives168(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_162(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives168(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives168(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_162(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_curlybrackedclose_171(bool is_can, std::shared_ptr<leaf::parsing::instance::switch_>& actual, leaf::parsing::instance::switch__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_switch_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::switch_> fake;
    switch__state state;
    if (!m_switch_roundbrackedopen_expression_roundbrackedclose_161(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while169_170(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_171(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::switch_> leaf::parsing::instance::p_match_switch_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::switch_>();
    std::shared_ptr<leaf::parsing::instance::switch_> fake;
    switch__state state;
    resetable resetable2(*this);
    resetable resetable3(*this);
    if (m_switch_roundbrackedopen_expression_roundbrackedclose_161(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_switch_roundbrackedopen_expression_roundbrackedclose_161(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (while169_170(true, fake, state, depth + 1))
    {
        resetable4.reset();
        while169_170(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_curlybrackedclose_171(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_curlybrackedclose_171(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_eol_172(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__eol(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__eol(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_173(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives174(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly_terminate>& actual, leaf::parsing::instance::assembly_terminate_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_eol_172(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_eol_172(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_curlybrackedclose_173(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_curlybrackedclose_173(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_assembly_terminate(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::assembly_terminate> fake;
    assembly_terminate_state state;
    if (!alternatives174(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::assembly_terminate> leaf::parsing::instance::p_match_assembly_terminate(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::assembly_terminate>();
    std::shared_ptr<leaf::parsing::instance::assembly_terminate> fake;
    assembly_terminate_state state;
    resetable resetable2(*this);
    if (alternatives174(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives174(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_assembly_curlybrackedopen_175(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__assembly(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__curly_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__assembly(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto l9 = token__curly_bracked_open(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_176(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_assemblyterminate_177(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_assembly_terminate(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_assembly_terminate(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_scalar_178(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_scalar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->args.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_179(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->args.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_180(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->args.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_181(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->args.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives182(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_scalar_178(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scalar_178(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerbinary_179(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_179(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_180(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_180(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_181(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_181(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while183_184(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_assemblyterminate_177(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            alternatives182(true, actual, state, depth + 1);
            resetable resetable2(*this);
            cond3 = m_assemblyterminate_177(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            alternatives182(false, actual, state, depth + 1);
            resetable resetable2(*this);
            cond3 = m_assemblyterminate_177(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_ident_185(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->opcode.push_back(val4);
    skip();
    while183_184(false, actual, state, depth + 1);
    return true;
}
bool leaf::parsing::instance::while186_187(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_curlybrackedclose_176(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            if (m_ident_185(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: ident ({ Token: ident}) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_176(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (m_ident_185(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: ident ({ Token: ident}) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_176(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_curlybrackedclose_188(bool is_can, std::shared_ptr<leaf::parsing::instance::assembly>& actual, leaf::parsing::instance::assembly_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_assembly(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::assembly> fake;
    assembly_state state;
    if (!m_assembly_curlybrackedopen_175(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while186_187(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_188(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::assembly> leaf::parsing::instance::p_match_assembly(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::assembly>();
    std::shared_ptr<leaf::parsing::instance::assembly> fake;
    assembly_state state;
    resetable resetable2(*this);
    if (m_assembly_curlybrackedopen_175(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_assembly_curlybrackedopen_175(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while186_187(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while186_187(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_curlybrackedclose_188(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_curlybrackedclose_188(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_pragma_189(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragmas = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_whileloop_190(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_while_loop(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_while_loop(depth + 1);
    actual->content = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ifelse_191(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_if_else(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_if_else(depth + 1);
    actual->content = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_switch_192(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_switch_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_switch_(depth + 1);
    actual->content = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_scope_193(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->content = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_assembly_194(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_assembly(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_assembly(depth + 1);
    actual->content = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives195(bool is_can, std::shared_ptr<leaf::parsing::instance::control_structure>& actual, leaf::parsing::instance::control_structure_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_pragma_189(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_189(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_whileloop_190(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_whileloop_190(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ifelse_191(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ifelse_191(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_switch_192(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_switch_192(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_scope_193(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scope_193(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_assembly_194(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_assembly_194(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_control_structure(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::control_structure> fake;
    control_structure_state state;
    if (!alternatives195(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::control_structure> leaf::parsing::instance::p_match_control_structure(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::control_structure>();
    std::shared_ptr<leaf::parsing::instance::control_structure> fake;
    control_structure_state state;
    resetable resetable2(*this);
    if (alternatives195(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives195(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_alloc_196(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_alloc(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_alloc(depth + 1);
    actual->part_alloc = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_free_197(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_free(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_free(depth + 1);
    actual->part_free = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_call_198(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_call(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_call(depth + 1);
    actual->part_call = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_199(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->part_ident = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives200(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain_start>& actual, leaf::parsing::instance::exp_chain_start_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_alloc_196(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_alloc_196(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_free_197(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_free_197(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_call_198(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_call_198(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_199(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_199(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_exp_chain_start(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_chain_start> fake;
    exp_chain_start_state state;
    if (!alternatives200(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::exp_chain_start> leaf::parsing::instance::p_match_exp_chain_start(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_chain_start>();
    std::shared_ptr<leaf::parsing::instance::exp_chain_start> fake;
    exp_chain_start_state state;
    resetable resetable2(*this);
    if (alternatives200(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives200(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_typeof_201(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_typeof_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_typeof_(depth + 1);
    actual->typeof_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_nameof_202(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_nameof(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_nameof(depth + 1);
    actual->nameof = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_sizeof_203(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_sizeof_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_sizeof_(depth + 1);
    actual->sizeof_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_scalar_204(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_scalar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_false_205(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_false_(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_false_(depth + 1).value(), tok::FALSE_);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_true_206(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_true_(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_true_(depth + 1).value(), tok::TRUE_);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_207(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_208(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_209(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_string_210(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string(depth + 1).value(), tok::STRING);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_char_211(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_char_(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_char_(depth + 1).value(), tok::CHAR_);
    actual->t = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives212(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_constant>& actual, leaf::parsing::instance::exp_constant_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_typeof_201(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typeof_201(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_nameof_202(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_nameof_202(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_sizeof_203(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_sizeof_203(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_scalar_204(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scalar_204(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_false_205(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_false_205(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_true_206(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_true_206(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_207(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_207(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerbinary_208(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_208(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_209(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_209(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_string_210(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_string_210(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_char_211(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_char_211(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_exp_constant(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_constant> fake;
    exp_constant_state state;
    if (!alternatives212(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::exp_constant> leaf::parsing::instance::p_match_exp_constant(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_constant>();
    std::shared_ptr<leaf::parsing::instance::exp_constant> fake;
    exp_constant_state state;
    resetable resetable2(*this);
    if (alternatives212(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives212(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_scalarliteral_213(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scalar_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scalar_literal(depth + 1);
    actual->scalar = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhexliteral_214(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_integer_hex_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_integer_hex_literal(depth + 1);
    actual->integer_hex = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinaryliteral_215(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_integer_binary_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_integer_binary_literal(depth + 1);
    actual->integer_binary = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerliteral_216(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_integer_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_integer_literal(depth + 1);
    actual->integer = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_charliteral_217(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_char_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_char_literal(depth + 1);
    actual->character = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringliteral_218(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_string_literal(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_string_literal(depth + 1);
    actual->string = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expconstant_219(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_exp_constant(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_exp_constant(depth + 1);
    actual->constant = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives220(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_value>& actual, leaf::parsing::instance::exp_value_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_scalarliteral_213(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scalarliteral_213(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhexliteral_214(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhexliteral_214(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerbinaryliteral_215(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinaryliteral_215(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerliteral_216(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerliteral_216(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_charliteral_217(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_charliteral_217(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_stringliteral_218(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_stringliteral_218(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_expconstant_219(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_expconstant_219(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_exp_value(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_value> fake;
    exp_value_state state;
    if (!alternatives220(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::exp_value> leaf::parsing::instance::p_match_exp_value(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_value>();
    std::shared_ptr<leaf::parsing::instance::exp_value> fake;
    exp_value_state state;
    resetable resetable2(*this);
    if (alternatives220(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives220(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_roundbrackedopen_expression_roundbrackedclose_221(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__round_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_expression(depth + 1);
    actual->value = val8;
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_expchain_222(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_chain(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_chain(depth + 1);
    actual->value = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expvalue_223(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_exp_value(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_exp_value(depth + 1);
    actual->value = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives224(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_nullar>& actual, leaf::parsing::instance::exp_nullar_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_roundbrackedopen_expression_roundbrackedclose_221(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_roundbrackedopen_expression_roundbrackedclose_221(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_expchain_222(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_expchain_222(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_expvalue_223(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_expvalue_223(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_exp_nullar(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_nullar> fake;
    exp_nullar_state state;
    if (!alternatives224(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::exp_nullar> leaf::parsing::instance::p_match_exp_nullar(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_nullar>();
    std::shared_ptr<leaf::parsing::instance::exp_nullar> fake;
    exp_nullar_state state;
    resetable resetable2(*this);
    if (alternatives224(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives224(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_exclamation_expunary_225(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__exclamation(depth + 1).value(), tok::_EXCLAMATION);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->value = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_tilde_expunary_226(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__tilde(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__tilde(depth + 1).value(), tok::_TILDE);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->value = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_minus_expunary_227(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_minus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_minus(depth + 1).value(), tok::MINUS);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->value = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_plus_expunary_228(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_plus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_plus(depth + 1).value(), tok::PLUS);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->value = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_roundbrackedopen_typematch_roundbrackedclose_expunary_229(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__round_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_type_match(depth + 1);
    actual->cast_target = val8;
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto val11 = p_match_exp_unary(depth + 1);
    actual->value = val11;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expnullar_230(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_exp_nullar(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_exp_nullar(depth + 1);
    actual->value = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives231(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_unary>& actual, leaf::parsing::instance::exp_unary_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_exclamation_expunary_225(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_exclamation_expunary_225(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_tilde_expunary_226(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_tilde_expunary_226(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_minus_expunary_227(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_minus_expunary_227(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_plus_expunary_228(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_plus_expunary_228(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_roundbrackedopen_typematch_roundbrackedclose_expunary_229(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_roundbrackedopen_typematch_roundbrackedclose_expunary_229(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_expnullar_230(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_expnullar_230(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_exp_unary(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_unary> fake;
    exp_unary_state state;
    if (!alternatives231(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::exp_unary> leaf::parsing::instance::p_match_exp_unary(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_unary>();
    std::shared_ptr<leaf::parsing::instance::exp_unary> fake;
    exp_unary_state state;
    resetable resetable2(*this);
    if (alternatives231(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives231(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_expor_equal_expression_232(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_or(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = lr_match_exp_or(depth + 1);
    actual->assign_to = val4;
    skip();
    auto l6 = token__equal(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    auto val7 = p_match_expression(depth + 1);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expor_233(bool is_can, std::shared_ptr<leaf::parsing::instance::expression>& actual, leaf::parsing::instance::expression_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_or(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_or(depth + 1);
    actual->exp = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_expression(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::expression> fake;
    expression_state state;
    if (!m_expor_equal_expression_232(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_expor_233(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::expression> leaf::parsing::instance::p_match_expression(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::expression>();
    std::shared_ptr<leaf::parsing::instance::expression> fake;
    expression_state state;
    resetable resetable2(*this);
    if (m_expor_equal_expression_232(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_expor_equal_expression_232(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_expor_233(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_expor_233(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_public_234(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__public(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__public(depth + 1).value(), tok::_PUBLIC);
    actual->tok = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_local_235(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__local(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__local(depth + 1).value(), tok::_LOCAL);
    actual->tok = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_derived_236(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__derived(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__derived(depth + 1).value(), tok::_DERIVED);
    actual->tok = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_private_237(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__private(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__private(depth + 1).value(), tok::_PRIVATE);
    actual->tok = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives238(bool is_can, std::shared_ptr<leaf::parsing::instance::encapsulation>& actual, leaf::parsing::instance::encapsulation_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_public_234(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_public_234(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_local_235(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_local_235(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_derived_236(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_derived_236(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_private_237(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_private_237(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_encapsulation(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::encapsulation> fake;
    encapsulation_state state;
    if (!alternatives238(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::encapsulation> leaf::parsing::instance::p_match_encapsulation(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::encapsulation>();
    std::shared_ptr<leaf::parsing::instance::encapsulation> fake;
    encapsulation_state state;
    resetable resetable2(*this);
    if (alternatives238(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives238(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_239(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_240(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while241_242(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_239(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_240(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_239(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_240(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_239(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_namespace_identnavigation_243(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__namespace(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_ident_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__namespace(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = lr_match_ident_navigation(depth + 1);
    actual->name = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedopen_244(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_245(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_using_246(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_using_(depth + 1);
    actual->usings.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_namespace_247(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_namespace_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_namespace_(depth + 1);
    actual->namespaces.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_conversion_248(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_conversion(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_conversion(depth + 1);
    actual->conversions.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_class_249(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_class_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_class_(depth + 1);
    actual->classes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_method_250(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method(depth + 1);
    actual->methods.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_property_251(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_property(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_property(depth + 1);
    actual->properties.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_field_252(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_field(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_field(depth + 1);
    actual->fields.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragma_253(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragmas.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives254(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_using_246(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_using_246(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_namespace_247(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_namespace_247(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_conversion_248(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_conversion_248(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_class_249(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_class_249(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_method_250(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_method_250(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_property_251(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_property_251(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_field_252(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_field_252(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragma_253(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_253(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { using, namespace, conversion, class, method, property, field, pragma }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while255_256(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_curlybrackedclose_245(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives254(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_245(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives254(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives254(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_245(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_curlybrackedclose_257(bool is_can, std::shared_ptr<leaf::parsing::instance::namespace_>& actual, leaf::parsing::instance::namespace__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_namespace_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::namespace_> fake;
    namespace__state state;
    if (!while241_242(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_namespace_identnavigation_243(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedopen_244(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while255_256(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_257(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::namespace_> leaf::parsing::instance::p_match_namespace_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::namespace_>();
    std::shared_ptr<leaf::parsing::instance::namespace_> fake;
    namespace__state state;
    resetable resetable2(*this);
    if (while241_242(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while241_242(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_namespace_identnavigation_243(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_namespace_identnavigation_243(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_curlybrackedopen_244(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_curlybrackedopen_244(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (while255_256(true, fake, state, depth + 1))
    {
        resetable5.reset();
        while255_256(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (m_curlybrackedclose_257(true, fake, state, depth + 1))
    {
        resetable6.reset();
        m_curlybrackedclose_257(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_258(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_259(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while260_261(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_258(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_259(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_258(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_259(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_258(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_class_ident_262(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__class(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_encapsulation(depth + 1);
    actual->scope = val6;
    skip();
    auto l8 = token__class(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val9;
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedopen_263(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_curlybrackedclose_264(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_using_265(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_using_(depth + 1);
    actual->usings.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_indexer_266(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_indexer(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_indexer(depth + 1);
    actual->indexers.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_operatorbinaryoverload_267(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_operator_binary_overload(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_operator_binary_overload(depth + 1);
    actual->operators_binary.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_operatorunaryoverload_268(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_operator_unary_overload(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_operator_unary_overload(depth + 1);
    actual->operators_unary.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_conversion_269(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_conversion(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_conversion(depth + 1);
    actual->conversions.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_class_270(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_class_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_class_(depth + 1);
    actual->classes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_constructor_271(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_constructor(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_constructor(depth + 1);
    actual->constructors.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_destructor_272(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_destructor(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_destructor(depth + 1);
    actual->destructors.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_copystructor_273(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_copystructor(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_copystructor(depth + 1);
    actual->copystructors.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_property_274(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_property(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_property(depth + 1);
    actual->properties.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_field_275(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_field(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_field(depth + 1);
    actual->fields.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_method_276(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method(depth + 1);
    actual->methods.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragma_277(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragmas.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives278(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_using_265(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_using_265(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_indexer_266(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_indexer_266(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_operatorbinaryoverload_267(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_operatorbinaryoverload_267(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_operatorunaryoverload_268(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_operatorunaryoverload_268(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_conversion_269(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_conversion_269(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_class_270(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_class_270(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_constructor_271(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_constructor_271(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_destructor_272(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_destructor_272(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_copystructor_273(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_copystructor_273(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_property_274(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_property_274(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_field_275(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_field_275(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_method_276(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_method_276(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragma_277(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_277(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { using, indexer, operator-binary-overload, operator-unary-overload, conversion, class, constructor, destructor, copystructor, property, field, method, pragma }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while279_280(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_curlybrackedclose_264(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives278(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_264(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives278(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives278(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_curlybrackedclose_264(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_curlybrackedclose_281(bool is_can, std::shared_ptr<leaf::parsing::instance::class_>& actual, leaf::parsing::instance::class__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__curly_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__curly_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_class_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::class_> fake;
    class__state state;
    if (!while260_261(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_class_ident_262(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedopen_263(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while279_280(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_curlybrackedclose_281(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::class_> leaf::parsing::instance::p_match_class_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::class_>();
    std::shared_ptr<leaf::parsing::instance::class_> fake;
    class__state state;
    resetable resetable2(*this);
    if (while260_261(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while260_261(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_class_ident_262(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_class_ident_262(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_curlybrackedopen_263(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_curlybrackedopen_263(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (while279_280(true, fake, state, depth + 1))
    {
        resetable5.reset();
        while279_280(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (m_curlybrackedclose_281(true, fake, state, depth + 1))
    {
        resetable6.reset();
        m_curlybrackedclose_281(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_282(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_283(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while284_285(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_282(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_283(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_282(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_283(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_282(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_ident_286(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->type = val4;
    skip();
    auto val5 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_287(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__equal(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_expvalue_288(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_value(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__equal(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_exp_value(depth + 1);
    actual->value = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::if289_290(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default>& actual, leaf::parsing::instance::method_arglist_item_with_default_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_equal_287(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_equal_expvalue_288(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: exp-value (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_equal_expvalue_288(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: exp-value (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_method_arglist_item_with_default(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default> fake;
    method_arglist_item_with_default_state state;
    if (!while284_285(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_ident_286(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if289_290(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default> leaf::parsing::instance::p_match_method_arglist_item_with_default(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::method_arglist_item_with_default>();
    std::shared_ptr<leaf::parsing::instance::method_arglist_item_with_default> fake;
    method_arglist_item_with_default_state state;
    resetable resetable2(*this);
    if (while284_285(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while284_285(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_typematch_ident_286(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_typematch_ident_286(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if289_290(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if289_290(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_291(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_292(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while293_294(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_291(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_292(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_291(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_292(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_291(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_ident_295(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_item>& actual, leaf::parsing::instance::method_arglist_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->type = val4;
    skip();
    auto val5 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_method_arglist_item(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::method_arglist_item> fake;
    method_arglist_item_state state;
    if (!while293_294(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_ident_295(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::method_arglist_item> leaf::parsing::instance::p_match_method_arglist_item(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::method_arglist_item>();
    std::shared_ptr<leaf::parsing::instance::method_arglist_item> fake;
    method_arglist_item_state state;
    resetable resetable2(*this);
    if (while293_294(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while293_294(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_typematch_ident_295(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_typematch_ident_295(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_roundbrackedopen_296(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_methodarglistitemwithdefault_297(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist_item_with_default(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_method_arglist_item_with_default(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_methodarglistitemwithdefault_298(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist_item_with_default(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist_item_with_default(depth + 1);
    actual->args.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_roundbrackedclose_299(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_methodarglistitemwithdefault_300(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_method_arglist_item_with_default(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_method_arglist_item_with_default(depth + 1);
    actual->args.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives301(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_comma_methodarglistitemwithdefault_300(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_methodarglistitemwithdefault_300(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { ,, method-arglist-item-with-default }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while302_303(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_roundbrackedclose_299(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives301(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_roundbrackedclose_299(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives301(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives301(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_roundbrackedclose_299(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_comma_304(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_305(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if306_307(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_comma_304(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_comma_305(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_comma_305(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::if308_309(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_methodarglistitemwithdefault_297(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_methodarglistitemwithdefault_298(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: method-arglist-item-with-default (XCG.Parsing.Production) }", depth);
                return false;
            }
            while302_303(true, actual, state, depth + 1);
            if306_307(true, actual, state, depth + 1);
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_methodarglistitemwithdefault_298(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: method-arglist-item-with-default (XCG.Parsing.Production) }", depth);
                return false;
            }
            while302_303(false, actual, state, depth + 1);
            if306_307(false, actual, state, depth + 1);
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_roundbrackedclose_310(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist>& actual, leaf::parsing::instance::method_arglist_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_method_arglist(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::method_arglist> fake;
    method_arglist_state state;
    if (!m_roundbrackedopen_296(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if308_309(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedclose_310(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::method_arglist> leaf::parsing::instance::p_match_method_arglist(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::method_arglist>();
    std::shared_ptr<leaf::parsing::instance::method_arglist> fake;
    method_arglist_state state;
    resetable resetable2(*this);
    if (m_roundbrackedopen_296(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_roundbrackedopen_296(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (if308_309(true, fake, state, depth + 1))
    {
        resetable3.reset();
        if308_309(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_roundbrackedclose_310(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_roundbrackedclose_310(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_squarebrackedopen_311(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__square_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_methodarglistitem_312(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist_item(depth + 1);
    actual->args.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_squarebrackedclose_313(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__square_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_methodarglistitem_314(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_method_arglist_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_method_arglist_item(depth + 1);
    actual->args.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives315(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_comma_methodarglistitem_314(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_methodarglistitem_314(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { ,, method-arglist-item }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while316_317(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_squarebrackedclose_313(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives315(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_squarebrackedclose_313(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives315(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives315(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_squarebrackedclose_313(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_comma_318(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_319(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if320_321(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_comma_318(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_comma_319(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_comma_319(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: , ({ Token: , (,)}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_squarebrackedclose_322(bool is_can, std::shared_ptr<leaf::parsing::instance::method_arglist_indexer>& actual, leaf::parsing::instance::method_arglist_indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__square_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_method_arglist_indexer(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::method_arglist_indexer> fake;
    method_arglist_indexer_state state;
    if (!m_squarebrackedopen_311(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglistitem_312(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while316_317(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if320_321(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_squarebrackedclose_322(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::method_arglist_indexer> leaf::parsing::instance::p_match_method_arglist_indexer(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::method_arglist_indexer>();
    std::shared_ptr<leaf::parsing::instance::method_arglist_indexer> fake;
    method_arglist_indexer_state state;
    resetable resetable2(*this);
    if (m_squarebrackedopen_311(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_squarebrackedopen_311(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_methodarglistitem_312(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_methodarglistitem_312(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (while316_317(true, fake, state, depth + 1))
    {
        resetable4.reset();
        while316_317(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (if320_321(true, fake, state, depth + 1))
    {
        resetable5.reset();
        if320_321(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (m_squarebrackedclose_322(true, fake, state, depth + 1))
    {
        resetable6.reset();
        m_squarebrackedclose_322(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_323(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_324(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while325_326(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_323(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_324(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_323(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_324(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_323(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_327(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_encapsulation(depth + 1);
    actual->encaps = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_328(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_329(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if330_331(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_sealed_328(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_sealed_329(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_sealed_329(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_virtual_332(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_virtual_333(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if334_335(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_virtual_332(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_virtual_333(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_virtual_333(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_unbound_336(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_unbound_337(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if338_339(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_unbound_336(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_unbound_337(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_unbound_337(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_inline_340(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__inline(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__inline(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_inline_341(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__inline(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__inline(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if342_343(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_inline_340(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_inline_341(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: inline ({ Token: inline (inline)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_inline_341(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: inline ({ Token: inline (inline)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_344(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_type_match(depth + 1);
    actual->return_type = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_345(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_346(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_347(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if348_349(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_346(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_347(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_347(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_methodarglist_scope_350(bool is_can, std::shared_ptr<leaf::parsing::instance::method>& actual, leaf::parsing::instance::method_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist(depth + 1);
    actual->arglist = val2;
    skip();
    auto val3 = p_match_scope(depth + 1);
    actual->body = val3;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_method(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::method> fake;
    method_state state;
    if (!while325_326(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_327(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if330_331(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if334_335(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if338_339(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if342_343(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_344(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_ident_345(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if348_349(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglist_scope_350(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::method> leaf::parsing::instance::p_match_method(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::method>();
    std::shared_ptr<leaf::parsing::instance::method> fake;
    method_state state;
    resetable resetable2(*this);
    if (while325_326(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while325_326(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_327(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_327(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if330_331(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if330_331(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (if334_335(true, fake, state, depth + 1))
    {
        resetable5.reset();
        if334_335(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (if338_339(true, fake, state, depth + 1))
    {
        resetable6.reset();
        if338_339(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable7(*this);
    if (if342_343(true, fake, state, depth + 1))
    {
        resetable7.reset();
        if342_343(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable8(*this);
    if (m_typematch_344(true, fake, state, depth + 1))
    {
        resetable8.reset();
        m_typematch_344(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable9(*this);
    if (m_ident_345(true, fake, state, depth + 1))
    {
        resetable9.reset();
        m_ident_345(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable10(*this);
    if (if348_349(true, fake, state, depth + 1))
    {
        resetable10.reset();
        if348_349(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable11(*this);
    if (m_methodarglist_scope_350(true, fake, state, depth + 1))
    {
        resetable11.reset();
        m_methodarglist_scope_350(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_351(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_352(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while353_354(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_351(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_352(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_351(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_352(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_351(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_355(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_encapsulation(depth + 1);
    actual->encaps = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_356(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_357(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if358_359(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_356(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_357(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_357(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_methodarglist_scope_360(bool is_can, std::shared_ptr<leaf::parsing::instance::constructor>& actual, leaf::parsing::instance::constructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist(depth + 1);
    actual->arglist = val2;
    skip();
    auto val3 = p_match_scope(depth + 1);
    actual->body = val3;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_constructor(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::constructor> fake;
    constructor_state state;
    if (!while353_354(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_355(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if358_359(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglist_scope_360(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::constructor> leaf::parsing::instance::p_match_constructor(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::constructor>();
    std::shared_ptr<leaf::parsing::instance::constructor> fake;
    constructor_state state;
    resetable resetable2(*this);
    if (while353_354(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while353_354(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_355(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_355(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if358_359(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if358_359(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_methodarglist_scope_360(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_methodarglist_scope_360(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_361(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_362(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while363_364(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_361(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_362(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_361(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_362(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_361(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_tilde_365(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__tilde(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_encapsulation(depth + 1);
    actual->encaps = val4;
    skip();
    auto l6 = token__tilde(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_366(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_367(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if368_369(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_366(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_367(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_367(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_methodarglist_scope_370(bool is_can, std::shared_ptr<leaf::parsing::instance::destructor>& actual, leaf::parsing::instance::destructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist(depth + 1);
    actual->arglist = val2;
    skip();
    auto val3 = p_match_scope(depth + 1);
    actual->body = val3;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_destructor(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::destructor> fake;
    destructor_state state;
    if (!while363_364(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_tilde_365(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if368_369(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglist_scope_370(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::destructor> leaf::parsing::instance::p_match_destructor(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::destructor>();
    std::shared_ptr<leaf::parsing::instance::destructor> fake;
    destructor_state state;
    resetable resetable2(*this);
    if (while363_364(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while363_364(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_tilde_365(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_tilde_365(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if368_369(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if368_369(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_methodarglist_scope_370(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_methodarglist_scope_370(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_371(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_372(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while373_374(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_371(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_372(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_371(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_372(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_371(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_plus_375(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_plus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_encapsulation(depth + 1);
    actual->encaps = val4;
    skip();
    auto l6 = token_plus(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_376(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_377(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if378_379(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_376(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_377(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_377(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_methodarglist_380(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist(depth + 1);
    actual->arglist = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_scope_381(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_delete_382(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__delete(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__equal(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto l9 = token__delete(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives383(bool is_can, std::shared_ptr<leaf::parsing::instance::copystructor>& actual, leaf::parsing::instance::copystructor_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_scope_381(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scope_381(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_equal_delete_382(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_equal_delete_382(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_copystructor(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::copystructor> fake;
    copystructor_state state;
    if (!while373_374(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_plus_375(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if378_379(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglist_380(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives383(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::copystructor> leaf::parsing::instance::p_match_copystructor(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::copystructor>();
    std::shared_ptr<leaf::parsing::instance::copystructor> fake;
    copystructor_state state;
    resetable resetable2(*this);
    if (while373_374(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while373_374(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_plus_375(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_plus_375(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if378_379(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if378_379(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_methodarglist_380(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_methodarglist_380(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (alternatives383(true, fake, state, depth + 1))
    {
        resetable6.reset();
        alternatives383(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_384(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_385(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while386_387(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_384(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_385(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_384(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_385(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_384(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_unbound_conversion_typematch_388(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__conversion(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_encapsulation(depth + 1);
    actual->encaps = val6;
    skip();
    auto l8 = token__unbound(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto l10 = token__conversion(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto val11 = p_match_type_match(depth + 1);
    actual->target_type = val11;
    skip();
    return true;
}
bool leaf::parsing::instance::m_roundbrackedopen_typematch_ident_roundbrackedclose_389(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__round_bracked_open(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto val10 = p_match_type_match(depth + 1);
    actual->source_type = val10;
    skip();
    auto val11 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val11;
    skip();
    auto l13 = token__round_bracked_close(depth + 1).value();
    for (;l13 != 0; l13--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_scope_390(bool is_can, std::shared_ptr<leaf::parsing::instance::conversion>& actual, leaf::parsing::instance::conversion_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_conversion(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::conversion> fake;
    conversion_state state;
    if (!while386_387(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_unbound_conversion_typematch_388(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedopen_typematch_ident_roundbrackedclose_389(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_scope_390(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::conversion> leaf::parsing::instance::p_match_conversion(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::conversion>();
    std::shared_ptr<leaf::parsing::instance::conversion> fake;
    conversion_state state;
    resetable resetable2(*this);
    if (while386_387(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while386_387(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_unbound_conversion_typematch_388(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_unbound_conversion_typematch_388(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_roundbrackedopen_typematch_ident_roundbrackedclose_389(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_roundbrackedopen_typematch_ident_roundbrackedclose_389(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_scope_390(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_scope_390(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_391(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_392(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while393_394(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_391(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_392(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_391(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_392(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_391(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_typematch_395(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_encapsulation(depth + 1);
    actual->encaps = val2;
    skip();
    auto val3 = p_match_type_match(depth + 1);
    actual->target_type = val3;
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_396(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_397(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if398_399(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_396(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_397(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_397(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_methodarglistindexer_scopegetset_400(bool is_can, std::shared_ptr<leaf::parsing::instance::indexer>& actual, leaf::parsing::instance::indexer_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method_arglist_indexer(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope_getset(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method_arglist_indexer(depth + 1);
    actual->arglist = val2;
    skip();
    auto val3 = p_match_scope_getset(depth + 1);
    actual->body = val3;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_indexer(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::indexer> fake;
    indexer_state state;
    if (!while393_394(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_typematch_395(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if398_399(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_methodarglistindexer_scopegetset_400(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::indexer> leaf::parsing::instance::p_match_indexer(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::indexer>();
    std::shared_ptr<leaf::parsing::instance::indexer> fake;
    indexer_state state;
    resetable resetable2(*this);
    if (while393_394(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while393_394(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_typematch_395(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_typematch_395(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if398_399(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if398_399(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_methodarglistindexer_scopegetset_400(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_methodarglistindexer_scopegetset_400(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_401(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_402(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while403_404(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_401(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_402(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_401(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_402(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_401(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_unbound_405(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_encapsulation(depth + 1);
    actual->encaps = val4;
    skip();
    auto l6 = token__unbound(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_inline_406(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__inline(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__inline(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if407_408(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_inline_406(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_operator_409(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__operator(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->target_type = val4;
    skip();
    auto l6 = token__operator(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_410(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_411(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if412_413(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_410(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_411(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_411(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_roundbrackedopen_methodarglistitem_roundbrackedclose_414(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_method_arglist_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__round_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_method_arglist_item(depth + 1);
    actual->left = val8;
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_plus_415(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_plus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_plus(depth + 1).value(), tok::PLUS);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_minus_416(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_minus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_minus(depth + 1).value(), tok::MINUS);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_star_417(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_star(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_star(depth + 1).value(), tok::STAR);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_slash_418(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_slash(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_slash(depth + 1).value(), tok::SLASH);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_lessthenlessthenlessthen_419(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_less_then_less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_less_then_less_then(depth + 1).value(), tok::_LESS_THEN_LESS_THEN_LESS_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_lessthenlessthen_420(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_less_then(depth + 1).value(), tok::_LESS_THEN_LESS_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_lessthenequal_421(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_equal(depth + 1).value(), tok::_LESS_THEN_EQUAL);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_lessthen_422(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then(depth + 1).value(), tok::_LESS_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_greaterthengreaterthengreaterthen_423(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_greater_then_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_greater_then_greater_then(depth + 1).value(), tok::_GREATER_THEN_GREATER_THEN_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_greaterthengreaterthen_424(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_greater_then(depth + 1).value(), tok::_GREATER_THEN_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_greaterthenequal_425(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_equal(depth + 1).value(), tok::_GREATER_THEN_EQUAL);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_greaterthen_426(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then(depth + 1).value(), tok::_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_verticalbarverticalbar_427(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__vertical_bar_vertical_bar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__vertical_bar_vertical_bar(depth + 1).value(), tok::_VERTICAL_BAR_VERTICAL_BAR);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_verticalbar_428(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__vertical_bar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__vertical_bar(depth + 1).value(), tok::_VERTICAL_BAR);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ampersandampersand_429(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__ampersand_ampersand(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__ampersand_ampersand(depth + 1).value(), tok::_AMPERSAND_AMPERSAND);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ampersand_430(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__ampersand(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__ampersand(depth + 1).value(), tok::_AMPERSAND);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_equalequalequal_431(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal_equal_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__equal_equal_equal(depth + 1).value(), tok::_EQUAL_EQUAL_EQUAL);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_equalequal_432(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__equal_equal(depth + 1).value(), tok::_EQUAL_EQUAL);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exclamationequal_433(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__exclamation_equal(depth + 1).value(), tok::_EXCLAMATION_EQUAL);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_circumflex_434(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__circumflex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__circumflex(depth + 1).value(), tok::_CIRCUMFLEX);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives435(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_plus_415(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_plus_415(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_minus_416(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_minus_416(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_star_417(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_star_417(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_slash_418(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_slash_418(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_lessthenlessthenlessthen_419(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_lessthenlessthenlessthen_419(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_lessthenlessthen_420(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_lessthenlessthen_420(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_lessthenequal_421(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_lessthenequal_421(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_lessthen_422(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_lessthen_422(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_greaterthengreaterthengreaterthen_423(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_greaterthengreaterthengreaterthen_423(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_greaterthengreaterthen_424(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_greaterthengreaterthen_424(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_greaterthenequal_425(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_greaterthenequal_425(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_greaterthen_426(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_greaterthen_426(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_verticalbarverticalbar_427(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_verticalbarverticalbar_427(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_verticalbar_428(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_verticalbar_428(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ampersandampersand_429(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ampersandampersand_429(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ampersand_430(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ampersand_430(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_equalequalequal_431(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_equalequalequal_431(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_equalequal_432(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_equalequal_432(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_exclamationequal_433(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_exclamationequal_433(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_circumflex_434(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_circumflex_434(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::m_roundbrackedopen_methodarglistitem_roundbrackedclose_436(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_method_arglist_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__round_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_method_arglist_item(depth + 1);
    actual->right = val8;
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_scope_437(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_binary_overload>& actual, leaf::parsing::instance::operator_binary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_operator_binary_overload(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::operator_binary_overload> fake;
    operator_binary_overload_state state;
    if (!while403_404(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_unbound_405(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if407_408(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_operator_409(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if412_413(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedopen_methodarglistitem_roundbrackedclose_414(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives435(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedopen_methodarglistitem_roundbrackedclose_436(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_scope_437(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::operator_binary_overload> leaf::parsing::instance::p_match_operator_binary_overload(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::operator_binary_overload>();
    std::shared_ptr<leaf::parsing::instance::operator_binary_overload> fake;
    operator_binary_overload_state state;
    resetable resetable2(*this);
    if (while403_404(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while403_404(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_unbound_405(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_unbound_405(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if407_408(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if407_408(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_typematch_operator_409(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_typematch_operator_409(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (if412_413(true, fake, state, depth + 1))
    {
        resetable6.reset();
        if412_413(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable7(*this);
    if (m_roundbrackedopen_methodarglistitem_roundbrackedclose_414(true, fake, state, depth + 1))
    {
        resetable7.reset();
        m_roundbrackedopen_methodarglistitem_roundbrackedclose_414(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable8(*this);
    if (alternatives435(true, fake, state, depth + 1))
    {
        resetable8.reset();
        alternatives435(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable9(*this);
    if (m_roundbrackedopen_methodarglistitem_roundbrackedclose_436(true, fake, state, depth + 1))
    {
        resetable9.reset();
        m_roundbrackedopen_methodarglistitem_roundbrackedclose_436(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable10(*this);
    if (m_scope_437(true, fake, state, depth + 1))
    {
        resetable10.reset();
        m_scope_437(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_438(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_439(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while440_441(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_438(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_439(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_438(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_439(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_438(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_unbound_442(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_encapsulation(depth + 1);
    actual->encaps = val4;
    skip();
    auto l6 = token__unbound(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_inline_443(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__inline(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__inline(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if444_445(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_inline_443(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (!is_can)
            {
                actual->is_inline = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_operator_446(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__operator(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->target_type = val4;
    skip();
    auto l6 = token__operator(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_447(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_template_definition(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinition_448(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::if449_450(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_templatedefinition_447(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_templatedefinition_448(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_templatedefinition_448(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: template-definition (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_plus_451(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_plus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_plus(depth + 1).value(), tok::PLUS);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_minus_452(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_minus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_minus(depth + 1).value(), tok::MINUS);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exclamation_453(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__exclamation(depth + 1).value(), tok::_EXCLAMATION);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_tilde_454(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__tilde(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__tilde(depth + 1).value(), tok::_TILDE);
    actual->operator_ = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives455(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_plus_451(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_plus_451(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_minus_452(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_minus_452(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_exclamation_453(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_exclamation_453(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_tilde_454(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_tilde_454(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::m_roundbrackedopen_methodarglistitem_roundbrackedclose_456(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_method_arglist_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__round_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_method_arglist_item(depth + 1);
    actual->right = val8;
    skip();
    auto l10 = token__round_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_scope_457(bool is_can, std::shared_ptr<leaf::parsing::instance::operator_unary_overload>& actual, leaf::parsing::instance::operator_unary_overload_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_scope(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_scope(depth + 1);
    actual->body = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_operator_unary_overload(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::operator_unary_overload> fake;
    operator_unary_overload_state state;
    if (!while440_441(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_unbound_442(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if444_445(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_operator_446(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if449_450(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives455(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedopen_methodarglistitem_roundbrackedclose_456(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_scope_457(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::operator_unary_overload> leaf::parsing::instance::p_match_operator_unary_overload(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::operator_unary_overload>();
    std::shared_ptr<leaf::parsing::instance::operator_unary_overload> fake;
    operator_unary_overload_state state;
    resetable resetable2(*this);
    if (while440_441(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while440_441(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_unbound_442(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_unbound_442(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if444_445(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if444_445(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_typematch_operator_446(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_typematch_operator_446(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (if449_450(true, fake, state, depth + 1))
    {
        resetable6.reset();
        if449_450(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable7(*this);
    if (alternatives455(true, fake, state, depth + 1))
    {
        resetable7.reset();
        alternatives455(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable8(*this);
    if (m_roundbrackedopen_methodarglistitem_roundbrackedclose_456(true, fake, state, depth + 1))
    {
        resetable8.reset();
        m_roundbrackedopen_methodarglistitem_roundbrackedclose_456(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable9(*this);
    if (m_scope_457(true, fake, state, depth + 1))
    {
        resetable9.reset();
        m_scope_457(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_458(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_459(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while460_461(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_458(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_459(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_458(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_459(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_458(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_462(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_encapsulation(depth + 1);
    actual->encaps = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_463(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_464(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if465_466(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_sealed_463(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_sealed_464(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_sealed_464(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_virtual_467(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_virtual_468(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if469_470(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_virtual_467(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_virtual_468(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_virtual_468(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_unbound_471(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_unbound_472(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if473_474(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_unbound_471(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_unbound_472(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_unbound_472(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_ident_scopegetset_475(bool is_can, std::shared_ptr<leaf::parsing::instance::property>& actual, leaf::parsing::instance::property_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_scope_getset(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->target_type = val4;
    skip();
    auto val5 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val5;
    skip();
    auto val6 = p_match_scope_getset(depth + 1);
    actual->body = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_property(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::property> fake;
    property_state state;
    if (!while460_461(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_462(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if465_466(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if469_470(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if473_474(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_ident_scopegetset_475(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::property> leaf::parsing::instance::p_match_property(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::property>();
    std::shared_ptr<leaf::parsing::instance::property> fake;
    property_state state;
    resetable resetable2(*this);
    if (while460_461(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while460_461(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_462(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_462(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if465_466(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if465_466(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (if469_470(true, fake, state, depth + 1))
    {
        resetable5.reset();
        if469_470(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (if473_474(true, fake, state, depth + 1))
    {
        resetable6.reset();
        if473_474(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable7(*this);
    if (m_typematch_ident_scopegetset_475(true, fake, state, depth + 1))
    {
        resetable7.reset();
        m_typematch_ident_scopegetset_475(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_attribute_476(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_attribute(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_attribute_477(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_attribute(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_attribute(depth + 1);
    actual->attributes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while478_479(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_attribute_476(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_477(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_476(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_attribute_477(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: attribute (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_attribute_476(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_encapsulation_480(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_encapsulation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_encapsulation(depth + 1);
    actual->encaps = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_481(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_sealed_482(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sealed(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__sealed(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if483_484(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_sealed_481(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_sealed_482(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_sealed_482(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: sealed ({ Token: sealed (sealed)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_sealed = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_virtual_485(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_virtual_486(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__virtual(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__virtual(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if487_488(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_virtual_485(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_virtual_486(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_virtual_486(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: virtual ({ Token: virtual (virtual)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_virtual = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_unbound_489(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_unbound_490(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__unbound(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__unbound(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::if491_492(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_unbound_489(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_unbound_490(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_unbound_490(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: unbound ({ Token: unbound (unbound)}) }", depth);
                return false;
            }
            if (!is_can)
            {
                actual->is_static = true;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_typematch_ident_semicolon_493(bool is_can, std::shared_ptr<leaf::parsing::instance::field>& actual, leaf::parsing::instance::field_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__semicolon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_type_match(depth + 1);
    actual->target_type = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val7;
    skip();
    auto l9 = token__semicolon(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_field(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::field> fake;
    field_state state;
    if (!while478_479(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_encapsulation_480(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if483_484(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if487_488(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if491_492(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_typematch_ident_semicolon_493(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::field> leaf::parsing::instance::p_match_field(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::field>();
    std::shared_ptr<leaf::parsing::instance::field> fake;
    field_state state;
    resetable resetable2(*this);
    if (while478_479(true, fake, state, depth + 1))
    {
        resetable2.reset();
        while478_479(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_encapsulation_480(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_encapsulation_480(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if483_484(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if483_484(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (if487_488(true, fake, state, depth + 1))
    {
        resetable5.reset();
        if487_488(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable6(*this);
    if (if491_492(true, fake, state, depth + 1))
    {
        resetable6.reset();
        if491_492(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable7(*this);
    if (m_typematch_ident_semicolon_493(true, fake, state, depth + 1))
    {
        resetable7.reset();
        m_typematch_ident_semicolon_493(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_using_494(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__using(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__using(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_namespace_identnavigation_495(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__namespace(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_ident_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__namespace(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = lr_match_ident_navigation(depth + 1);
    actual->ident = val6;
    skip();
    if (!is_can)
    {
        actual->is_namespace = true;
    }
    return true;
}
bool leaf::parsing::instance::m_class_identnavigation_496(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__class(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_ident_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__class(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = lr_match_ident_navigation(depth + 1);
    actual->ident = val6;
    skip();
    if (!is_can)
    {
        actual->is_class = true;
    }
    return true;
}
bool leaf::parsing::instance::alternatives497(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_namespace_identnavigation_495(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_namespace_identnavigation_495(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_class_identnavigation_496(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_class_identnavigation_496(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::m_equal_498(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__equal(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_ident_499(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__equal(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->alias = val8;
    skip();
    return true;
}
bool leaf::parsing::instance::if500_501(bool is_can, std::shared_ptr<leaf::parsing::instance::using_>& actual, leaf::parsing::instance::using__state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_equal_498(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_equal_ident_499(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: ident ({ Token: ident}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_equal_ident_499(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: ident ({ Token: ident}) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_using_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::using_> fake;
    using__state state;
    if (!m_using_494(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives497(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if500_501(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::using_> leaf::parsing::instance::p_match_using_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::using_>();
    std::shared_ptr<leaf::parsing::instance::using_> fake;
    using__state state;
    resetable resetable2(*this);
    if (m_using_494(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_using_494(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (alternatives497(true, fake, state, depth + 1))
    {
        resetable3.reset();
        alternatives497(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (if500_501(true, fake, state, depth + 1))
    {
        resetable4.reset();
        if500_501(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_callbody_502(bool is_can, std::shared_ptr<leaf::parsing::instance::call>& actual, leaf::parsing::instance::call_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_call_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->method = val4;
    skip();
    auto val5 = p_match_call_body(depth + 1);
    actual->body = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_call(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::call> fake;
    call_state state;
    if (!m_ident_callbody_502(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::call> leaf::parsing::instance::p_match_call(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::call>();
    std::shared_ptr<leaf::parsing::instance::call> fake;
    call_state state;
    resetable resetable2(*this);
    if (m_ident_callbody_502(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_ident_callbody_502(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_roundbrackedopen_503(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_open(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_expression_504(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_expression(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_expression_505(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_expression(depth + 1);
    actual->args.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_roundbrackedclose_506(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_expression_507(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_expression(depth + 1);
    actual->args.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_508(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives509(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_comma_expression_507(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_expression_507(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_comma_508(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_508(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { ,, expression, , }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while510_511(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_roundbrackedclose_506(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives509(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_roundbrackedclose_506(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives509(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives509(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_roundbrackedclose_506(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::if512_513(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_expression_504(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_expression_505(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: expression (XCG.Parsing.Production) }", depth);
                return false;
            }
            while510_511(true, actual, state, depth + 1);
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_expression_505(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: expression (XCG.Parsing.Production) }", depth);
                return false;
            }
            while510_511(false, actual, state, depth + 1);
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_roundbrackedclose_514(bool is_can, std::shared_ptr<leaf::parsing::instance::call_body>& actual, leaf::parsing::instance::call_body_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__round_bracked_close(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__round_bracked_close(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_call_body(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::call_body> fake;
    call_body_state state;
    if (!m_roundbrackedopen_503(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if512_513(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_roundbrackedclose_514(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::call_body> leaf::parsing::instance::p_match_call_body(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::call_body>();
    std::shared_ptr<leaf::parsing::instance::call_body> fake;
    call_body_state state;
    resetable resetable2(*this);
    if (m_roundbrackedopen_503(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_roundbrackedopen_503(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (if512_513(true, fake, state, depth + 1))
    {
        resetable3.reset();
        if512_513(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_roundbrackedclose_514(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_roundbrackedclose_514(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_free_expression_515(bool is_can, std::shared_ptr<leaf::parsing::instance::free>& actual, leaf::parsing::instance::free_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__free(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__free(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_expression(depth + 1);
    actual->value = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_free(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::free> fake;
    free_state state;
    if (!m_free_expression_515(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::free> leaf::parsing::instance::p_match_free(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::free>();
    std::shared_ptr<leaf::parsing::instance::free> fake;
    free_state state;
    resetable resetable2(*this);
    if (m_free_expression_515(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_free_expression_515(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_alloc_stack_typenavigation_squarebrackedopen_expression_squarebrackedclose_516(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__alloc(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__stack(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__square_bracked_open(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l8 = token__square_bracked_close(depth + 1);
    if (l8.has_value())
    {
        for (auto i9 = l8.value(); i9 != 0; i9--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l11 = token__alloc(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto l13 = token__stack(depth + 1).value();
    for (;l13 != 0; l13--)
    {
        next();
    }
    skip();
    auto val14 = lr_match_type_navigation(depth + 1);
    actual->type = val14;
    skip();
    auto l16 = token__square_bracked_open(depth + 1).value();
    for (;l16 != 0; l16--)
    {
        next();
    }
    skip();
    auto val17 = p_match_expression(depth + 1);
    actual->exp = val17;
    skip();
    auto l19 = token__square_bracked_close(depth + 1).value();
    for (;l19 != 0; l19--)
    {
        next();
    }
    skip();
    if (!is_can)
    {
        actual->is_stack = true;
    }
    if (!is_can)
    {
        actual->is_heap = false;
    }
    return true;
}
bool leaf::parsing::instance::m_alloc_stack_typenavigation_callbody_517(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__alloc(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__stack(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_call_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__alloc(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto l9 = token__stack(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto val10 = lr_match_type_navigation(depth + 1);
    actual->type = val10;
    skip();
    auto val11 = p_match_call_body(depth + 1);
    actual->body = val11;
    skip();
    if (!is_can)
    {
        actual->is_stack = true;
    }
    if (!is_can)
    {
        actual->is_heap = false;
    }
    return true;
}
bool leaf::parsing::instance::m_alloc_heap_typenavigation_squarebrackedopen_expression_squarebrackedclose_518(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__alloc(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__heap(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__square_bracked_open(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l8 = token__square_bracked_close(depth + 1);
    if (l8.has_value())
    {
        for (auto i9 = l8.value(); i9 != 0; i9--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l11 = token__alloc(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto l13 = token__heap(depth + 1).value();
    for (;l13 != 0; l13--)
    {
        next();
    }
    skip();
    auto val14 = lr_match_type_navigation(depth + 1);
    actual->type = val14;
    skip();
    auto l16 = token__square_bracked_open(depth + 1).value();
    for (;l16 != 0; l16--)
    {
        next();
    }
    skip();
    auto val17 = p_match_expression(depth + 1);
    actual->exp = val17;
    skip();
    auto l19 = token__square_bracked_close(depth + 1).value();
    for (;l19 != 0; l19--)
    {
        next();
    }
    skip();
    if (!is_can)
    {
        actual->is_stack = false;
    }
    if (!is_can)
    {
        actual->is_heap = true;
    }
    return true;
}
bool leaf::parsing::instance::m_alloc_heap_typenavigation_callbody_519(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__alloc(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__heap(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_call_body(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__alloc(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto l9 = token__heap(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto val10 = lr_match_type_navigation(depth + 1);
    actual->type = val10;
    skip();
    auto val11 = p_match_call_body(depth + 1);
    actual->body = val11;
    skip();
    if (!is_can)
    {
        actual->is_stack = false;
    }
    if (!is_can)
    {
        actual->is_heap = true;
    }
    return true;
}
bool leaf::parsing::instance::alternatives520(bool is_can, std::shared_ptr<leaf::parsing::instance::alloc>& actual, leaf::parsing::instance::alloc_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_alloc_stack_typenavigation_squarebrackedopen_expression_squarebrackedclose_516(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_alloc_stack_typenavigation_squarebrackedopen_expression_squarebrackedclose_516(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_alloc_stack_typenavigation_callbody_517(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_alloc_stack_typenavigation_callbody_517(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_alloc_heap_typenavigation_squarebrackedopen_expression_squarebrackedclose_518(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_alloc_heap_typenavigation_squarebrackedopen_expression_squarebrackedclose_518(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_alloc_heap_typenavigation_callbody_519(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_alloc_heap_typenavigation_callbody_519(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_alloc(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::alloc> fake;
    alloc_state state;
    if (!alternatives520(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::alloc> leaf::parsing::instance::p_match_alloc(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::alloc>();
    std::shared_ptr<leaf::parsing::instance::alloc> fake;
    alloc_state state;
    resetable resetable2(*this);
    if (alternatives520(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives520(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_521(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage_item>& actual, leaf::parsing::instance::template_usage_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->key = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_template_usage_item(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::template_usage_item> fake;
    template_usage_item_state state;
    if (!m_ident_521(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::template_usage_item> leaf::parsing::instance::p_match_template_usage_item(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::template_usage_item>();
    std::shared_ptr<leaf::parsing::instance::template_usage_item> fake;
    template_usage_item_state state;
    resetable resetable2(*this);
    if (m_ident_521(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_ident_521(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_lessthen_522(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__less_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templateusageitem_523(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_usage_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_usage_item(depth + 1);
    actual->items.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_524(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_templateusageitem_525(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_template_usage_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_template_usage_item(depth + 1);
    actual->items.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives526(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_comma_templateusageitem_525(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_templateusageitem_525(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { ,, template-usage-item }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while527_528(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_comma_524(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            while (!alternatives526(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_comma_524(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (!alternatives526(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives526(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_comma_524(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_greaterthen_529(bool is_can, std::shared_ptr<leaf::parsing::instance::template_usage>& actual, leaf::parsing::instance::template_usage_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__greater_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_template_usage(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::template_usage> fake;
    template_usage_state state;
    if (!m_lessthen_522(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_templateusageitem_523(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while527_528(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_greaterthen_529(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::template_usage> leaf::parsing::instance::p_match_template_usage(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::template_usage>();
    std::shared_ptr<leaf::parsing::instance::template_usage> fake;
    template_usage_state state;
    resetable resetable2(*this);
    if (m_lessthen_522(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_lessthen_522(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_templateusageitem_523(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_templateusageitem_523(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (while527_528(true, fake, state, depth + 1))
    {
        resetable4.reset();
        while527_528(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_greaterthen_529(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_greaterthen_529(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_530(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->key = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_531(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__equal(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_equal_expvalue_532(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_value(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__equal(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_exp_value(depth + 1);
    actual->value = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::if533_534(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition_item>& actual, leaf::parsing::instance::template_definition_item_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_equal_531(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            if (m_equal_expvalue_532(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: exp-value (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            if (m_equal_expvalue_532(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: = ({ Token: = (=)}), $ref: exp-value (XCG.Parsing.Production) }", depth);
                return false;
            }
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_template_definition_item(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::template_definition_item> fake;
    template_definition_item_state state;
    if (!m_ident_530(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!if533_534(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::template_definition_item> leaf::parsing::instance::p_match_template_definition_item(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::template_definition_item>();
    std::shared_ptr<leaf::parsing::instance::template_definition_item> fake;
    template_definition_item_state state;
    resetable resetable2(*this);
    if (m_ident_530(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_ident_530(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (if533_534(true, fake, state, depth + 1))
    {
        resetable3.reset();
        if533_534(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_lessthen_535(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__less_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_templatedefinitionitem_536(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_definition_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_definition_item(depth + 1);
    actual->items.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_537(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_comma_templatedefinitionitem_538(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__comma(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_template_definition_item(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__comma(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_template_definition_item(depth + 1);
    actual->items.push_back(val6);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives539(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_comma_templatedefinitionitem_538(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_comma_templatedefinitionitem_538(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { ,, template-definition-item }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while540_541(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_comma_537(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            while (!alternatives539(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_comma_537(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (!alternatives539(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives539(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_comma_537(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_greaterthen_542(bool is_can, std::shared_ptr<leaf::parsing::instance::template_definition>& actual, leaf::parsing::instance::template_definition_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__greater_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_template_definition(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::template_definition> fake;
    template_definition_state state;
    if (!m_lessthen_535(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_templatedefinitionitem_536(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while540_541(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_greaterthen_542(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::template_definition> leaf::parsing::instance::p_match_template_definition(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::template_definition>();
    std::shared_ptr<leaf::parsing::instance::template_definition> fake;
    template_definition_state state;
    resetable resetable2(*this);
    if (m_lessthen_535(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_lessthen_535(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_templatedefinitionitem_536(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_templatedefinitionitem_536(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (while540_541(true, fake, state, depth + 1))
    {
        resetable4.reset();
        while540_541(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_greaterthen_542(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_greaterthen_542(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_typeof_roundbrackedopen_typematch_roundbrackedclose_543(bool is_can, std::shared_ptr<leaf::parsing::instance::typeof_>& actual, leaf::parsing::instance::typeof__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__typeof(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__typeof(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = p_match_type_match(depth + 1);
    actual->value = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_typeof_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::typeof_> fake;
    typeof__state state;
    if (!m_typeof_roundbrackedopen_typematch_roundbrackedclose_543(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::typeof_> leaf::parsing::instance::p_match_typeof_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::typeof_>();
    std::shared_ptr<leaf::parsing::instance::typeof_> fake;
    typeof__state state;
    resetable resetable2(*this);
    if (m_typeof_roundbrackedopen_typematch_roundbrackedclose_543(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_typeof_roundbrackedopen_typematch_roundbrackedclose_543(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_nameof_roundbrackedopen_expor_roundbrackedclose_544(bool is_can, std::shared_ptr<leaf::parsing::instance::nameof>& actual, leaf::parsing::instance::nameof_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__nameof(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_or(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__nameof(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = lr_match_exp_or(depth + 1);
    actual->value = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_nameof(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::nameof> fake;
    nameof_state state;
    if (!m_nameof_roundbrackedopen_expor_roundbrackedclose_544(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::nameof> leaf::parsing::instance::p_match_nameof(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::nameof>();
    std::shared_ptr<leaf::parsing::instance::nameof> fake;
    nameof_state state;
    resetable resetable2(*this);
    if (m_nameof_roundbrackedopen_expor_roundbrackedclose_544(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_nameof_roundbrackedopen_expor_roundbrackedclose_544(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_sizeof_roundbrackedopen_typematch_roundbrackedclose_545(bool is_can, std::shared_ptr<leaf::parsing::instance::sizeof_>& actual, leaf::parsing::instance::sizeof__state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__sizeof(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__round_bracked_open(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token__round_bracked_close(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l9 = token__sizeof(depth + 1).value();
    for (;l9 != 0; l9--)
    {
        next();
    }
    skip();
    auto l11 = token__round_bracked_open(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    auto val12 = p_match_type_match(depth + 1);
    actual->type = val12;
    skip();
    auto l14 = token__round_bracked_close(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_sizeof_(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::sizeof_> fake;
    sizeof__state state;
    if (!m_sizeof_roundbrackedopen_typematch_roundbrackedclose_545(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::sizeof_> leaf::parsing::instance::p_match_sizeof_(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::sizeof_>();
    std::shared_ptr<leaf::parsing::instance::sizeof_> fake;
    sizeof__state state;
    resetable resetable2(*this);
    if (m_sizeof_roundbrackedopen_typematch_roundbrackedclose_545(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_sizeof_roundbrackedopen_typematch_roundbrackedclose_545(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_typenavigation_squarebrackedopen_squarebrackedclose_star_546(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__square_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__square_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_star(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = lr_match_type_navigation(depth + 1);
    actual->base = val8;
    skip();
    auto l10 = token__square_bracked_open(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    auto l12 = token__square_bracked_close(depth + 1).value();
    for (;l12 != 0; l12--)
    {
        next();
    }
    skip();
    auto l14 = token_star(depth + 1).value();
    for (;l14 != 0; l14--)
    {
        next();
    }
    skip();
    if (!is_can)
    {
        actual->is_array = true;
    }
    if (!is_can)
    {
        actual->is_heap = true;
    }
    return true;
}
bool leaf::parsing::instance::m_typenavigation_star_547(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_star(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = lr_match_type_navigation(depth + 1);
    actual->base = val4;
    skip();
    auto l6 = token_star(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    if (!is_can)
    {
        actual->is_array = false;
    }
    if (!is_can)
    {
        actual->is_heap = true;
    }
    return true;
}
bool leaf::parsing::instance::m_typenavigation_548(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_type_navigation(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_type_navigation(depth + 1);
    actual->base = val2;
    skip();
    if (!is_can)
    {
        actual->is_array = false;
    }
    if (!is_can)
    {
        actual->is_heap = false;
    }
    return true;
}
bool leaf::parsing::instance::alternatives549(bool is_can, std::shared_ptr<leaf::parsing::instance::type_match>& actual, leaf::parsing::instance::type_match_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_typenavigation_squarebrackedopen_squarebrackedclose_star_546(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typenavigation_squarebrackedopen_squarebrackedclose_star_546(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typenavigation_star_547(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typenavigation_star_547(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_typenavigation_548(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_typenavigation_548(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_type_match(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::type_match> fake;
    type_match_state state;
    if (!alternatives549(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::type_match> leaf::parsing::instance::p_match_type_match(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::type_match>();
    std::shared_ptr<leaf::parsing::instance::type_match> fake;
    type_match_state state;
    resetable resetable2(*this);
    if (alternatives549(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives549(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_stringformatablestart_550(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_start(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string_formatable_start(depth + 1).value(), tok::STRING_FORMATABLE_START);
    actual->parts.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::m_expression_551(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_expression(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatableend_552(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_end(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token_string_formatable_end(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatablecontinuation_553(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_continuation(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string_formatable_continuation(depth + 1).value(), tok::STRING_FORMATABLE_CONTINUATION);
    actual->parts.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::m_expression_554(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_expression(depth + 1);
    actual->parts.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while555_556(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_stringformatableend_552(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            if (m_stringformatablecontinuation_553(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: string-formatable-continuation ({ Token: string-formatable-continuation}) }", depth);
                return false;
            }
            if (m_expression_554(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: expression (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_stringformatableend_552(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (m_stringformatablecontinuation_553(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: string-formatable-continuation ({ Token: string-formatable-continuation}) }", depth);
                return false;
            }
            if (m_expression_554(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: expression (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_stringformatableend_552(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_stringformatableend_557(bool is_can, std::shared_ptr<leaf::parsing::instance::string_formatable>& actual, leaf::parsing::instance::string_formatable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_end(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string_formatable_end(depth + 1).value(), tok::STRING_FORMATABLE_END);
    actual->parts.push_back(val4);
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_string_formatable(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::string_formatable> fake;
    string_formatable_state state;
    if (!m_stringformatablestart_550(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_expression_551(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while555_556(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_stringformatableend_557(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::string_formatable> leaf::parsing::instance::p_match_string_formatable(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::string_formatable>();
    std::shared_ptr<leaf::parsing::instance::string_formatable> fake;
    string_formatable_state state;
    resetable resetable2(*this);
    if (m_stringformatablestart_550(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_stringformatablestart_550(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_expression_551(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_expression_551(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (while555_556(true, fake, state, depth + 1))
    {
        resetable4.reset();
        while555_556(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable5(*this);
    if (m_stringformatableend_557(true, fake, state, depth + 1))
    {
        resetable5.reset();
        m_stringformatableend_557(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_stringformatable_ident_558(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_string_formatable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = p_match_string_formatable(depth + 1);
    actual->value = val7;
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val8;
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatable_ident_559(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_string_formatable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_string_formatable(depth + 1);
    actual->value = val4;
    skip();
    auto val5 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_stringformatable_560(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_string_formatable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val4;
    skip();
    auto val5 = p_match_string_formatable(depth + 1);
    actual->value = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatable_561(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_string_formatable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_string_formatable(depth + 1);
    actual->value = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_stringformatablefake_ident_562(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_string_formatable_fake(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_string_formatable_fake(depth + 1).value(), tok::STRING_FORMATABLE_FAKE);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatablefake_ident_563(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_fake(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_string_formatable_fake(depth + 1).value(), tok::STRING_FORMATABLE_FAKE);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_stringformatablefake_564(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_string_formatable_fake(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_string_formatable_fake(depth + 1).value(), tok::STRING_FORMATABLE_FAKE);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_stringformatablefake_565(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string_formatable_fake(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string_formatable_fake(depth + 1).value(), tok::STRING_FORMATABLE_FAKE);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_string_ident_566(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_string(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_string(depth + 1).value(), tok::STRING);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_string_ident_567(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_string(depth + 1).value(), tok::STRING);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_string_568(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_string(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_string(depth + 1).value(), tok::STRING);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_string_569(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_string(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_string(depth + 1).value(), tok::STRING);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives570(bool is_can, std::shared_ptr<leaf::parsing::instance::string_literal>& actual, leaf::parsing::instance::string_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_stringformatable_ident_558(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_stringformatable_ident_558(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_stringformatable_ident_559(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_stringformatable_ident_559(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_stringformatable_560(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_stringformatable_560(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_stringformatable_561(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_stringformatable_561(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_stringformatablefake_ident_562(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_stringformatablefake_ident_562(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_stringformatablefake_ident_563(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_stringformatablefake_ident_563(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_stringformatablefake_564(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_stringformatablefake_564(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_stringformatablefake_565(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_stringformatablefake_565(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_string_ident_566(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_string_ident_566(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_string_ident_567(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_string_ident_567(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_string_568(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_string_568(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_string_569(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_string_569(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_string_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::string_literal> fake;
    string_literal_state state;
    if (!alternatives570(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::string_literal> leaf::parsing::instance::p_match_string_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::string_literal>();
    std::shared_ptr<leaf::parsing::instance::string_literal> fake;
    string_literal_state state;
    resetable resetable2(*this);
    if (alternatives570(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives570(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_scalar_ident_571(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_scalar(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_scalar_ident_572(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_scalar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_scalar_573(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_scalar(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_scalar_574(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_scalar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_scalar(depth + 1).value(), tok::SCALAR);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives575(bool is_can, std::shared_ptr<leaf::parsing::instance::scalar_literal>& actual, leaf::parsing::instance::scalar_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_scalar_ident_571(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_scalar_ident_571(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_scalar_ident_572(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scalar_ident_572(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_scalar_573(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_scalar_573(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_scalar_574(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_scalar_574(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_scalar_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::scalar_literal> fake;
    scalar_literal_state state;
    if (!alternatives575(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::scalar_literal> leaf::parsing::instance::p_match_scalar_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::scalar_literal>();
    std::shared_ptr<leaf::parsing::instance::scalar_literal> fake;
    scalar_literal_state state;
    resetable resetable2(*this);
    if (alternatives575(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives575(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_integerhex_ident_576(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer_hex(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_ident_577(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_integerhex_578(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer_hex(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_579(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives580(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_hex_literal>& actual, leaf::parsing::instance::integer_hex_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_integerhex_ident_576(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integerhex_ident_576(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_ident_577(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_ident_577(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_integerhex_578(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integerhex_578(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_579(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_579(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_integer_hex_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::integer_hex_literal> fake;
    integer_hex_literal_state state;
    if (!alternatives580(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::integer_hex_literal> leaf::parsing::instance::p_match_integer_hex_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::integer_hex_literal>();
    std::shared_ptr<leaf::parsing::instance::integer_hex_literal> fake;
    integer_hex_literal_state state;
    resetable resetable2(*this);
    if (alternatives580(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives580(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_integerbinary_ident_581(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer_binary(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_ident_582(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_integerbinary_583(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer_binary(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_584(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives585(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_binary_literal>& actual, leaf::parsing::instance::integer_binary_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_integerbinary_ident_581(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integerbinary_ident_581(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerbinary_ident_582(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_ident_582(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_integerbinary_583(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integerbinary_583(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerbinary_584(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_584(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_integer_binary_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::integer_binary_literal> fake;
    integer_binary_literal_state state;
    if (!alternatives585(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::integer_binary_literal> leaf::parsing::instance::p_match_integer_binary_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::integer_binary_literal>();
    std::shared_ptr<leaf::parsing::instance::integer_binary_literal> fake;
    integer_binary_literal_state state;
    resetable resetable2(*this);
    if (alternatives585(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives585(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_integer_ident_586(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_ident_587(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_integer_588(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_integer(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_589(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives590(bool is_can, std::shared_ptr<leaf::parsing::instance::integer_literal>& actual, leaf::parsing::instance::integer_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_integer_ident_586(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integer_ident_586(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_ident_587(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_ident_587(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_integer_588(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_integer_588(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_589(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_589(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_integer_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::integer_literal> fake;
    integer_literal_state state;
    if (!alternatives590(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::integer_literal> leaf::parsing::instance::p_match_integer_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::integer_literal>();
    std::shared_ptr<leaf::parsing::instance::integer_literal> fake;
    integer_literal_state state;
    resetable resetable2(*this);
    if (alternatives590(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives590(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_ident_char_ident_591(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_char_(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l6 = token_ident(depth + 1);
    if (l6.has_value())
    {
        for (auto i7 = l6.value(); i7 != 0; i7--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val8;
    skip();
    auto val9 = create_token(token_char_(depth + 1).value(), tok::CHAR_);
    actual->value = val9;
    skip();
    auto val10 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val10;
    skip();
    return true;
}
bool leaf::parsing::instance::m_char_ident_592(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_char_(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_char_(depth + 1).value(), tok::CHAR_);
    actual->value = val6;
    skip();
    auto val7 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->postfix = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_char_593(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_char_(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->prefix = val6;
    skip();
    auto val7 = create_token(token_char_(depth + 1).value(), tok::CHAR_);
    actual->value = val7;
    skip();
    return true;
}
bool leaf::parsing::instance::m_char_594(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_char_(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_char_(depth + 1).value(), tok::CHAR_);
    actual->value = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives595(bool is_can, std::shared_ptr<leaf::parsing::instance::char_literal>& actual, leaf::parsing::instance::char_literal_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_ident_char_ident_591(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_char_ident_591(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_char_ident_592(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_char_ident_592(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_ident_char_593(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_ident_char_593(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_char_594(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_char_594(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_char_literal(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::char_literal> fake;
    char_literal_state state;
    if (!alternatives595(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::char_literal> leaf::parsing::instance::p_match_char_literal(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::char_literal>();
    std::shared_ptr<leaf::parsing::instance::char_literal> fake;
    char_literal_state state;
    resetable resetable2(*this);
    if (alternatives595(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives595(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_typematch_ident_596(bool is_can, std::shared_ptr<leaf::parsing::instance::declaration>& actual, leaf::parsing::instance::declaration_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_type_match(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_type_match(depth + 1);
    actual->type = val4;
    skip();
    auto val5 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->name = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_declaration(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::declaration> fake;
    declaration_state state;
    if (!m_typematch_ident_596(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::declaration> leaf::parsing::instance::p_match_declaration(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::declaration>();
    std::shared_ptr<leaf::parsing::instance::declaration> fake;
    declaration_state state;
    resetable resetable2(*this);
    if (m_typematch_ident_596(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_typematch_ident_596(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_return_expression_semicolon_597(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__return(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__semicolon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__return(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_expression(depth + 1);
    actual->ret = val8;
    skip();
    auto l10 = token__semicolon(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_declaration_equal_expression_semicolon_598(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_declaration(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__semicolon(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val6 = p_match_declaration(depth + 1);
    actual->fwrd_decl = val6;
    skip();
    auto l8 = token__equal(depth + 1).value();
    for (;l8 != 0; l8--)
    {
        next();
    }
    skip();
    auto val9 = p_match_expression(depth + 1);
    actual->exp = val9;
    skip();
    auto l11 = token__semicolon(depth + 1).value();
    for (;l11 != 0; l11--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_declaration_semicolon_599(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_declaration(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__semicolon(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_declaration(depth + 1);
    actual->fwrd_decl = val4;
    skip();
    auto l6 = token__semicolon(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_expression_semicolon_600(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l2 = token__semicolon(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = p_match_expression(depth + 1);
    actual->exp = val4;
    skip();
    auto l6 = token__semicolon(depth + 1).value();
    for (;l6 != 0; l6--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_semicolon_601(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__semicolon(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__semicolon(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragma_602(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragma = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives603(bool is_can, std::shared_ptr<leaf::parsing::instance::statement>& actual, leaf::parsing::instance::statement_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_return_expression_semicolon_597(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_return_expression_semicolon_597(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_declaration_equal_expression_semicolon_598(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_declaration_equal_expression_semicolon_598(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_declaration_semicolon_599(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_declaration_semicolon_599(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_expression_semicolon_600(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_expression_semicolon_600(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_semicolon_601(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_semicolon_601(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragma_602(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_602(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_statement(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::statement> fake;
    statement_state state;
    if (!alternatives603(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::statement> leaf::parsing::instance::p_match_statement(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::statement>();
    std::shared_ptr<leaf::parsing::instance::statement> fake;
    statement_state state;
    resetable resetable2(*this);
    if (alternatives603(true, fake, state, depth + 1))
    {
        resetable2.reset();
        alternatives603(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_auto626_604(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__auto_626(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__auto_626(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_exclamationgreaterthen_605(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__exclamation_greater_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragmadisable_606(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma_disable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma_disable(depth + 1);
    actual->contents.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragmaenable_607(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma_enable(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma_enable(depth + 1);
    actual->contents.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragmasize_608(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma_size(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma_size(depth + 1);
    actual->contents.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragmaalign_609(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma_align(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma_align(depth + 1);
    actual->contents.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives610(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_pragmadisable_606(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragmadisable_606(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragmaenable_607(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragmaenable_607(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragmasize_608(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragmasize_608(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragmaalign_609(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragmaalign_609(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { pragma-disable, pragma-enable, pragma-size, pragma-align }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while611_612(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_exclamationgreaterthen_605(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives610(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = m_exclamationgreaterthen_605(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives610(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives610(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = m_exclamationgreaterthen_605(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::m_exclamationgreaterthen_613(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma>& actual, leaf::parsing::instance::pragma_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__exclamation_greater_then(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_pragma(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::pragma> fake;
    pragma_state state;
    if (!m_auto626_604(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while611_612(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_exclamationgreaterthen_613(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::pragma> leaf::parsing::instance::p_match_pragma(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::pragma>();
    std::shared_ptr<leaf::parsing::instance::pragma> fake;
    pragma_state state;
    resetable resetable2(*this);
    if (m_auto626_604(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_auto626_604(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while611_612(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while611_612(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable4(*this);
    if (m_exclamationgreaterthen_613(true, fake, state, depth + 1))
    {
        resetable4.reset();
        m_exclamationgreaterthen_613(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_align_614(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__align(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__align(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_615(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_616(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_617(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives618(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_align>& actual, leaf::parsing::instance::pragma_align_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_integerbinary_615(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_615(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_616(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_616(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_617(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_617(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_pragma_align(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::pragma_align> fake;
    pragma_align_state state;
    if (!m_align_614(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives618(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::pragma_align> leaf::parsing::instance::p_match_pragma_align(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::pragma_align>();
    std::shared_ptr<leaf::parsing::instance::pragma_align> fake;
    pragma_align_state state;
    resetable resetable2(*this);
    if (m_align_614(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_align_614(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (alternatives618(true, fake, state, depth + 1))
    {
        resetable3.reset();
        alternatives618(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_size_619(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__size(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__size(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerbinary_620(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_binary(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_binary(depth + 1).value(), tok::INTEGER_BINARY);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integerhex_621(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer_hex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer_hex(depth + 1).value(), tok::INTEGER_HEX);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::m_integer_622(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_integer(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_integer(depth + 1).value(), tok::INTEGER);
    actual->bytes = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives623(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_size>& actual, leaf::parsing::instance::pragma_size_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_integerbinary_620(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerbinary_620(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integerhex_621(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integerhex_621(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_integer_622(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_integer_622(false, actual, state, depth + 1);
            return true;
        }
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::p_can_pragma_size(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::pragma_size> fake;
    pragma_size_state state;
    if (!m_size_619(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!alternatives623(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::pragma_size> leaf::parsing::instance::p_match_pragma_size(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::pragma_size>();
    std::shared_ptr<leaf::parsing::instance::pragma_size> fake;
    pragma_size_state state;
    resetable resetable2(*this);
    if (m_size_619(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_size_619(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (alternatives623(true, fake, state, depth + 1))
    {
        resetable3.reset();
        alternatives623(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_disable_624(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__disable(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__disable(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_625(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_disable>& actual, leaf::parsing::instance::pragma_disable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->code = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_pragma_disable(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::pragma_disable> fake;
    pragma_disable_state state;
    if (!m_disable_624(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_ident_625(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::pragma_disable> leaf::parsing::instance::p_match_pragma_disable(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::pragma_disable>();
    std::shared_ptr<leaf::parsing::instance::pragma_disable> fake;
    pragma_disable_state state;
    resetable resetable2(*this);
    if (m_disable_624(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_disable_624(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_ident_625(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_ident_625(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_enable_626(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__enable(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__enable(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_627(bool is_can, std::shared_ptr<leaf::parsing::instance::pragma_enable>& actual, leaf::parsing::instance::pragma_enable_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->code = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::p_can_pragma_enable(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::pragma_enable> fake;
    pragma_enable_state state;
    if (!m_enable_626(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!m_ident_627(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::pragma_enable> leaf::parsing::instance::p_match_pragma_enable(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::pragma_enable>();
    std::shared_ptr<leaf::parsing::instance::pragma_enable> fake;
    pragma_enable_state state;
    resetable resetable2(*this);
    if (m_enable_626(true, fake, state, depth + 1))
    {
        resetable2.reset();
        m_enable_626(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (m_ident_627(true, fake, state, depth + 1))
    {
        resetable3.reset();
        m_ident_627(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_using_628(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_using_(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_using_629(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    p_match_using_(depth + 1);
    skip();
    return true;
}
bool leaf::parsing::instance::m_using_630(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_using_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_using_(depth + 1);
    actual->usings.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::while631_632(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = m_using_629(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        while (cond3 && current() != '\0')
        {
            if (m_using_630(true, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: using (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_using_629(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (cond3 && current() != '\0')
        {
            if (m_using_630(false, actual, state, depth + 1))
            {
                skip();
            }
            else if (is_can)
            {
                return false;
            }
            else
            {
                report("Failed to match { $ref: using (XCG.Parsing.Production) }", depth);
                return false;
            }
            resetable resetable2(*this);
            cond3 = m_using_629(true, actual, state, depth + 1);
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::if633_634(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond2 = m_using_628(true, actual, state, depth + 1);
    resetable1.reset();
    if (is_can)
    {
        if (cond2)
        {
            while631_632(true, actual, state, depth + 1);
            return true;
        }
        return true;
    }
    else
    {
        if (cond2)
        {
            while631_632(false, actual, state, depth + 1);
            return true;
        }
        return true;
    }
}
bool leaf::parsing::instance::m_namespace_635(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_namespace_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_namespace_(depth + 1);
    actual->namespaces.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_conversion_636(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_conversion(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_conversion(depth + 1);
    actual->conversions.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_class_637(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_class_(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_class_(depth + 1);
    actual->classes.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_method_638(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_method(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_method(depth + 1);
    actual->methods.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_property_639(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_property(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_property(depth + 1);
    actual->properties.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_field_640(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_field(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_field(depth + 1);
    actual->fields.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::m_pragma_641(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_pragma(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_pragma(depth + 1);
    actual->pragmas.push_back(val2);
    skip();
    return true;
}
bool leaf::parsing::instance::alternatives642(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (m_namespace_635(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_namespace_635(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_conversion_636(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_conversion_636(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_class_637(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_class_637(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_method_638(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_method_638(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_property_639(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_property_639(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_field_640(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_field_640(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (m_pragma_641(true, actual, state, depth + 1))
    {
        if (is_can)
        {
            return true;
        }
        else
        {
            resetable1.reset();
            m_pragma_641(false, actual, state, depth + 1);
            return true;
        }
    }
    else if (!is_can)
    {
        report("Failed to match one of the following: { namespace, conversion, class, method, property, field, pragma }", depth);
    }
    resetable1.reset();
    return false;
}
bool leaf::parsing::instance::while643_644(bool is_can, std::shared_ptr<leaf::parsing::instance::main>& actual, leaf::parsing::instance::main_state& state, size_t depth)
{
    resetable resetable1(*this);
    bool cond3 = current() == '\0';
    resetable1.reset();
    if (is_can)
    {
        while (!cond3 && current() != '\0')
        {
            while (!alternatives642(true, actual, state, depth + 1) && current() != '\0')
            {
                next();
            }
            resetable resetable2(*this);
            cond3 = current() == '\0';
            resetable2.reset();
        }
        return true;
    }
    else
    {
        while (!cond3 && current() != '\0')
        {
            if (!alternatives642(false, actual, state, depth + 1))
            {
                while (current() != '\0')
                {
                    resetable resetable4(*this);
                    if (alternatives642(true, actual, state, depth + 1))
                    {
                        resetable4.reset();
                        break;
                    }
                    next();
                }
            }
            resetable resetable2(*this);
            cond3 = current() == '\0';
            resetable2.reset();
        }
        return true;
    }
}
bool leaf::parsing::instance::p_can_main(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::main> fake;
    main_state state;
    if (!if633_634(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    else if (!while643_644(true, fake, state, depth + 1))
    {
        resetable1.reset();
        return false;
    }
    return true;
}
std::shared_ptr<leaf::parsing::instance::main> leaf::parsing::instance::p_match_main(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::main>();
    std::shared_ptr<leaf::parsing::instance::main> fake;
    main_state state;
    resetable resetable2(*this);
    if (if633_634(true, fake, state, depth + 1))
    {
        resetable2.reset();
        if633_634(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    resetable resetable3(*this);
    if (while643_644(true, fake, state, depth + 1))
    {
        resetable3.reset();
        while643_644(false, actual, state, depth + 1);
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
    }
    return actual;
}
bool leaf::parsing::instance::m_expchain_dot_call_645(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__dot(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_call(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l5 = token__dot(depth + 1).value();
    for (;l5 != 0; l5--)
    {
        next();
    }
    skip();
    auto val6 = p_match_call(depth + 1);
    actual->chain_call = val6;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expchain_dot_ident_646(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__dot(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__dot(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->chain_access = val8;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expchain_squarebrackedopen_expression_squarebrackedclose_647(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__square_bracked_open(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_expression(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token__square_bracked_close(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__square_bracked_open(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = p_match_expression(depth + 1);
    actual->chain_indexer = val8;
    skip();
    auto l10 = token__square_bracked_close(depth + 1).value();
    for (;l10 != 0; l10--)
    {
        next();
    }
    skip();
    return true;
}
bool leaf::parsing::instance::m_expchain_templateusage_648(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_usage(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_usage(depth + 1);
    actual->chain_template = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expchainstart_649(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_chain>& actual, leaf::parsing::instance::exp_chain_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_exp_chain_start(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_exp_chain_start(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_chain(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_chain> fake;
    exp_chain_state state;
    if (!m_expchainstart_649(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expchain_dot_call_645(true, fake, state, depth + 1))
        {
        }
        else if (m_expchain_dot_ident_646(true, fake, state, depth + 1))
        {
        }
        else if (m_expchain_squarebrackedopen_expression_squarebrackedclose_647(true, fake, state, depth + 1))
        {
        }
        else if (m_expchain_templateusage_648(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_chain> leaf::parsing::instance::lr_match_exp_chain(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_chain>();
    std::shared_ptr<leaf::parsing::instance::exp_chain> fake;
    exp_chain_state state;
    if (!m_expchainstart_649(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expchain_dot_call_645(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_chain>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expchain_dot_call_645(false, actual, state, depth + 1);
        }
        else if (m_expchain_dot_ident_646(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_chain>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expchain_dot_ident_646(false, actual, state, depth + 1);
        }
        else if (m_expchain_squarebrackedopen_expression_squarebrackedclose_647(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_chain>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expchain_squarebrackedopen_expression_squarebrackedclose_647(false, actual, state, depth + 1);
        }
        else if (m_expchain_templateusage_648(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_chain>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expchain_templateusage_648(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expbinary4_lessthenlessthen_expunary_650(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_less_then(depth + 1).value(), tok::_LESS_THEN_LESS_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary4_greaterthengreaterthen_expunary_651(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_greater_then(depth + 1).value(), tok::_GREATER_THEN_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary4_lessthenlessthenlessthen_expunary_652(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_less_then_less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_less_then_less_then(depth + 1).value(), tok::_LESS_THEN_LESS_THEN_LESS_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary4_greaterthengreaterthengreaterthen_expunary_653(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_greater_then_greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_greater_then_greater_then(depth + 1).value(), tok::_GREATER_THEN_GREATER_THEN_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = p_match_exp_unary(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expunary_654(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_4>& actual, leaf::parsing::instance::exp_binary_4_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_exp_unary(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_exp_unary(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_binary_4(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_binary_4> fake;
    exp_binary_4_state state;
    if (!m_expunary_654(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary4_lessthenlessthen_expunary_650(true, fake, state, depth + 1))
        {
        }
        else if (m_expbinary4_greaterthengreaterthen_expunary_651(true, fake, state, depth + 1))
        {
        }
        else if (m_expbinary4_lessthenlessthenlessthen_expunary_652(true, fake, state, depth + 1))
        {
        }
        else if (m_expbinary4_greaterthengreaterthengreaterthen_expunary_653(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_binary_4> leaf::parsing::instance::lr_match_exp_binary_4(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_binary_4>();
    std::shared_ptr<leaf::parsing::instance::exp_binary_4> fake;
    exp_binary_4_state state;
    if (!m_expunary_654(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary4_lessthenlessthen_expunary_650(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_4>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary4_lessthenlessthen_expunary_650(false, actual, state, depth + 1);
        }
        else if (m_expbinary4_greaterthengreaterthen_expunary_651(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_4>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary4_greaterthengreaterthen_expunary_651(false, actual, state, depth + 1);
        }
        else if (m_expbinary4_lessthenlessthenlessthen_expunary_652(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_4>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary4_lessthenlessthenlessthen_expunary_652(false, actual, state, depth + 1);
        }
        else if (m_expbinary4_greaterthengreaterthengreaterthen_expunary_653(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_4>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary4_greaterthengreaterthengreaterthen_expunary_653(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expbinary3_ampersand_expbinary4_655(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__ampersand(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_binary_4(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__ampersand(depth + 1).value(), tok::_AMPERSAND);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_binary_4(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary4_656(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_3>& actual, leaf::parsing::instance::exp_binary_3_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_binary_4(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_binary_4(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_binary_3(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_binary_3> fake;
    exp_binary_3_state state;
    if (!m_expbinary4_656(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary3_ampersand_expbinary4_655(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_binary_3> leaf::parsing::instance::lr_match_exp_binary_3(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_binary_3>();
    std::shared_ptr<leaf::parsing::instance::exp_binary_3> fake;
    exp_binary_3_state state;
    if (!m_expbinary4_656(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary3_ampersand_expbinary4_655(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_3>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary3_ampersand_expbinary4_655(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expbinary2_circumflex_expbinary3_657(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__circumflex(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_binary_3(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__circumflex(depth + 1).value(), tok::_CIRCUMFLEX);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_binary_3(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary3_658(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_2>& actual, leaf::parsing::instance::exp_binary_2_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_binary_3(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_binary_3(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_binary_2(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_binary_2> fake;
    exp_binary_2_state state;
    if (!m_expbinary3_658(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary2_circumflex_expbinary3_657(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_binary_2> leaf::parsing::instance::lr_match_exp_binary_2(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_binary_2>();
    std::shared_ptr<leaf::parsing::instance::exp_binary_2> fake;
    exp_binary_2_state state;
    if (!m_expbinary3_658(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary2_circumflex_expbinary3_657(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_2>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary2_circumflex_expbinary3_657(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expbinary1_verticalbar_expbinary2_659(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__vertical_bar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_binary_2(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__vertical_bar(depth + 1).value(), tok::_VERTICAL_BAR);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_binary_2(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary2_660(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_binary_1>& actual, leaf::parsing::instance::exp_binary_1_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_binary_2(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_binary_2(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_binary_1(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_binary_1> fake;
    exp_binary_1_state state;
    if (!m_expbinary2_660(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary1_verticalbar_expbinary2_659(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_binary_1> leaf::parsing::instance::lr_match_exp_binary_1(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_binary_1>();
    std::shared_ptr<leaf::parsing::instance::exp_binary_1> fake;
    exp_binary_1_state state;
    if (!m_expbinary2_660(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expbinary1_verticalbar_expbinary2_659(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_binary_1>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expbinary1_verticalbar_expbinary2_659(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_exparithmetic2_slash_expbinary1_661(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_slash(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_binary_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_slash(depth + 1).value(), tok::SLASH);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_binary_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exparithmetic2_star_expbinary1_662(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_star(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_binary_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_star(depth + 1).value(), tok::STAR);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_binary_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expbinary1_663(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2>& actual, leaf::parsing::instance::exp_arithmetic_2_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_binary_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_binary_1(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_arithmetic_2(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> fake;
    exp_arithmetic_2_state state;
    if (!m_expbinary1_663(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_exparithmetic2_slash_expbinary1_661(true, fake, state, depth + 1))
        {
        }
        else if (m_exparithmetic2_star_expbinary1_662(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> leaf::parsing::instance::lr_match_exp_arithmetic_2(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_2>();
    std::shared_ptr<leaf::parsing::instance::exp_arithmetic_2> fake;
    exp_arithmetic_2_state state;
    if (!m_expbinary1_663(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_exparithmetic2_slash_expbinary1_661(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_2>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_exparithmetic2_slash_expbinary1_661(false, actual, state, depth + 1);
        }
        else if (m_exparithmetic2_star_expbinary1_662(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_2>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_exparithmetic2_star_expbinary1_662(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_exparithmetic1_plus_exparithmetic2_664(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_plus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_2(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_plus(depth + 1).value(), tok::PLUS);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_2(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exparithmetic1_minus_exparithmetic2_665(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_minus(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_2(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_minus(depth + 1).value(), tok::MINUS);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_2(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exparithmetic2_666(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1>& actual, leaf::parsing::instance::exp_arithmetic_1_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_arithmetic_2(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_arithmetic_2(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_arithmetic_1(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> fake;
    exp_arithmetic_1_state state;
    if (!m_exparithmetic2_666(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_exparithmetic1_plus_exparithmetic2_664(true, fake, state, depth + 1))
        {
        }
        else if (m_exparithmetic1_minus_exparithmetic2_665(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> leaf::parsing::instance::lr_match_exp_arithmetic_1(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_1>();
    std::shared_ptr<leaf::parsing::instance::exp_arithmetic_1> fake;
    exp_arithmetic_1_state state;
    if (!m_exparithmetic2_666(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_exparithmetic1_plus_exparithmetic2_664(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_1>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_exparithmetic1_plus_exparithmetic2_664(false, actual, state, depth + 1);
        }
        else if (m_exparithmetic1_minus_exparithmetic2_665(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_arithmetic_1>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_exparithmetic1_minus_exparithmetic2_665(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expcompare_lessthenequal_exparithmetic1_667(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then_equal(depth + 1).value(), tok::_LESS_THEN_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expcompare_lessthen_exparithmetic1_668(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__less_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__less_then(depth + 1).value(), tok::_LESS_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expcompare_greaterthenequal_exparithmetic1_669(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then_equal(depth + 1).value(), tok::_GREATER_THEN_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expcompare_greaterthen_exparithmetic1_670(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__greater_then(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_arithmetic_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__greater_then(depth + 1).value(), tok::_GREATER_THEN);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_arithmetic_1(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_exparithmetic1_671(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_compare>& actual, leaf::parsing::instance::exp_compare_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_arithmetic_1(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_arithmetic_1(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_compare(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_compare> fake;
    exp_compare_state state;
    if (!m_exparithmetic1_671(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expcompare_lessthenequal_exparithmetic1_667(true, fake, state, depth + 1))
        {
        }
        else if (m_expcompare_lessthen_exparithmetic1_668(true, fake, state, depth + 1))
        {
        }
        else if (m_expcompare_greaterthenequal_exparithmetic1_669(true, fake, state, depth + 1))
        {
        }
        else if (m_expcompare_greaterthen_exparithmetic1_670(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_compare> leaf::parsing::instance::lr_match_exp_compare(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_compare>();
    std::shared_ptr<leaf::parsing::instance::exp_compare> fake;
    exp_compare_state state;
    if (!m_exparithmetic1_671(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expcompare_lessthenequal_exparithmetic1_667(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_compare>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expcompare_lessthenequal_exparithmetic1_667(false, actual, state, depth + 1);
        }
        else if (m_expcompare_lessthen_exparithmetic1_668(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_compare>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expcompare_lessthen_exparithmetic1_668(false, actual, state, depth + 1);
        }
        else if (m_expcompare_greaterthenequal_exparithmetic1_669(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_compare>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expcompare_greaterthenequal_exparithmetic1_669(false, actual, state, depth + 1);
        }
        else if (m_expcompare_greaterthen_exparithmetic1_670(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_compare>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expcompare_greaterthen_exparithmetic1_670(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expequality_exclamationequal_expcompare_672(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__exclamation_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_compare(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__exclamation_equal(depth + 1).value(), tok::_EXCLAMATION_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_compare(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expequality_equalequalequal_expcompare_673(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal_equal_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_compare(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__equal_equal_equal(depth + 1).value(), tok::_EQUAL_EQUAL_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_compare(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expequality_equalequal_expcompare_674(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__equal_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_compare(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__equal_equal(depth + 1).value(), tok::_EQUAL_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_compare(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expequality_tildeequal_expcompare_675(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__tilde_equal(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_compare(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__tilde_equal(depth + 1).value(), tok::_TILDE_EQUAL);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_compare(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expcompare_676(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_equality>& actual, leaf::parsing::instance::exp_equality_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_compare(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_compare(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_equality(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_equality> fake;
    exp_equality_state state;
    if (!m_expcompare_676(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expequality_exclamationequal_expcompare_672(true, fake, state, depth + 1))
        {
        }
        else if (m_expequality_equalequalequal_expcompare_673(true, fake, state, depth + 1))
        {
        }
        else if (m_expequality_equalequal_expcompare_674(true, fake, state, depth + 1))
        {
        }
        else if (m_expequality_tildeequal_expcompare_675(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_equality> leaf::parsing::instance::lr_match_exp_equality(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_equality>();
    std::shared_ptr<leaf::parsing::instance::exp_equality> fake;
    exp_equality_state state;
    if (!m_expcompare_676(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expequality_exclamationequal_expcompare_672(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_equality>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expequality_exclamationequal_expcompare_672(false, actual, state, depth + 1);
        }
        else if (m_expequality_equalequalequal_expcompare_673(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_equality>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expequality_equalequalequal_expcompare_673(false, actual, state, depth + 1);
        }
        else if (m_expequality_equalequal_expcompare_674(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_equality>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expequality_equalequal_expcompare_674(false, actual, state, depth + 1);
        }
        else if (m_expequality_tildeequal_expcompare_675(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_equality>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expequality_tildeequal_expcompare_675(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expand_ampersandampersand_expequality_677(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__ampersand_ampersand(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_equality(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__ampersand_ampersand(depth + 1).value(), tok::_AMPERSAND_AMPERSAND);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_equality(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expequality_678(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_and>& actual, leaf::parsing::instance::exp_and_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_equality(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_equality(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_and(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_and> fake;
    exp_and_state state;
    if (!m_expequality_678(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expand_ampersandampersand_expequality_677(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_and> leaf::parsing::instance::lr_match_exp_and(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_and>();
    std::shared_ptr<leaf::parsing::instance::exp_and> fake;
    exp_and_state state;
    if (!m_expequality_678(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expand_ampersandampersand_expequality_677(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_and>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expand_ampersandampersand_expequality_677(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_expor_verticalbarverticalbar_expand_679(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__vertical_bar_vertical_bar(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (lr_can_exp_and(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token__vertical_bar_vertical_bar(depth + 1).value(), tok::_VERTICAL_BAR_VERTICAL_BAR);
    actual->operator_ = val4;
    skip();
    auto val5 = lr_match_exp_and(depth + 1);
    actual->right = val5;
    skip();
    return true;
}
bool leaf::parsing::instance::m_expand_680(bool is_can, std::shared_ptr<leaf::parsing::instance::exp_or>& actual, leaf::parsing::instance::exp_or_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (lr_can_exp_and(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = lr_match_exp_and(depth + 1);
    actual->left = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_exp_or(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::exp_or> fake;
    exp_or_state state;
    if (!m_expand_680(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expor_verticalbarverticalbar_expand_679(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::exp_or> leaf::parsing::instance::lr_match_exp_or(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::exp_or>();
    std::shared_ptr<leaf::parsing::instance::exp_or> fake;
    exp_or_state state;
    if (!m_expand_680(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_expor_verticalbarverticalbar_expand_679(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::exp_or>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_expor_verticalbarverticalbar_expand_679(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_identnavigation_dot_ident_681(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__dot(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__dot(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->right = val8;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_682(bool is_can, std::shared_ptr<leaf::parsing::instance::ident_navigation>& actual, leaf::parsing::instance::ident_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->left = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_ident_navigation(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::ident_navigation> fake;
    ident_navigation_state state;
    if (!m_ident_682(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_identnavigation_dot_ident_681(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::ident_navigation> leaf::parsing::instance::lr_match_ident_navigation(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::ident_navigation>();
    std::shared_ptr<leaf::parsing::instance::ident_navigation> fake;
    ident_navigation_state state;
    if (!m_ident_682(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_identnavigation_dot_ident_681(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::ident_navigation>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_identnavigation_dot_ident_681(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
bool leaf::parsing::instance::m_typenavigation_dot_ident_templateusage_683(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__dot(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (p_can_template_usage(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__dot(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->right = val8;
    skip();
    auto val9 = p_match_template_usage(depth + 1);
    actual->template_ = val9;
    skip();
    return true;
}
bool leaf::parsing::instance::m_typenavigation_dot_ident_684(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token__dot(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    auto l4 = token_ident(depth + 1);
    if (l4.has_value())
    {
        for (auto i5 = l4.value(); i5 != 0; i5--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto l7 = token__dot(depth + 1).value();
    for (;l7 != 0; l7--)
    {
        next();
    }
    skip();
    auto val8 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->right = val8;
    skip();
    return true;
}
bool leaf::parsing::instance::m_typenavigation_templateusage_685(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    if (p_can_template_usage(depth + 1))
    {
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val2 = p_match_template_usage(depth + 1);
    actual->template_ = val2;
    skip();
    return true;
}
bool leaf::parsing::instance::m_ident_686(bool is_can, std::shared_ptr<leaf::parsing::instance::type_navigation>& actual, leaf::parsing::instance::type_navigation_state& state, size_t depth)
{
    resetable resetable1(*this);
    auto l2 = token_ident(depth + 1);
    if (l2.has_value())
    {
        for (auto i3 = l2.value(); i3 != 0; i3--)
        {
            next();
        }
        skip();
    }
    else if (is_can)
    {
        resetable1.reset();
        return false;
    }
    else
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return false;
    }
    if (is_can)
    {
        return true;
    }
    resetable1.reset();
    auto val4 = create_token(token_ident(depth + 1).value(), tok::IDENT);
    actual->left = val4;
    skip();
    return true;
}
bool leaf::parsing::instance::lr_can_type_navigation(size_t depth)
{
    resetable resetable1(*this);
    std::shared_ptr<leaf::parsing::instance::type_navigation> fake;
    type_navigation_state state;
    if (!m_ident_686(true, fake, state, depth + 1))
    {
        return false;
    }
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_typenavigation_dot_ident_templateusage_683(true, fake, state, depth + 1))
        {
        }
        else if (m_typenavigation_dot_ident_684(true, fake, state, depth + 1))
        {
        }
        else if (m_typenavigation_templateusage_685(true, fake, state, depth + 1))
        {
        }
        else
        {
            return true;
        }
    }
}
std::shared_ptr<leaf::parsing::instance::type_navigation> leaf::parsing::instance::lr_match_type_navigation(size_t depth)
{
    auto actual = std::make_shared<leaf::parsing::instance::type_navigation>();
    std::shared_ptr<leaf::parsing::instance::type_navigation> fake;
    type_navigation_state state;
    if (!m_ident_686(false, actual, state, depth + 1))
    {
        report("Something moved wrong (todo: improve error messages)", depth);
        return {};
    }
    bool is_first2 = true;
    while (true)
    {
        skip();
        resetable resetable1(*this);
        if (m_typenavigation_dot_ident_templateusage_683(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::type_navigation>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_typenavigation_dot_ident_templateusage_683(false, actual, state, depth + 1);
        }
        else if (m_typenavigation_dot_ident_684(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::type_navigation>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_typenavigation_dot_ident_684(false, actual, state, depth + 1);
        }
        else if (m_typenavigation_templateusage_685(true, fake, state, depth + 1))
        {
            resetable1.reset();
            if (!is_first2)
            {
                auto tmp_actual3 = actual;
                actual = std::make_shared<leaf::parsing::instance::type_navigation>();
                actual->left = tmp_actual3;
            }
            is_first2 = false;
            m_typenavigation_templateusage_685(false, actual, state, depth + 1);
        }
        else
        {
            resetable1.reset();
            break;
        }
    }
    return actual;
}
void leaf::parsing::instance::skip()
{
    while (m_contents.length() > m_offset)
    {
        char c = m_contents[m_offset];
        switch (c)
        {
            case '\r':
            case '\t':
            case ' ': m_column++; m_offset++; break;
            case '\n': m_line++; m_column = 1; m_offset++; break;
            default:
            {
                bool wasMatched1 = false;
                if (m_contents.length() > m_offset + 2 && m_contents[m_offset + 0] == '/' && m_contents[m_offset + 1] == '/')
                {
                    wasMatched1 = true;
                    for (size_t i2 = 0; i2 < 2; i2++)
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                    while (m_contents.length() > m_offset + 2 && !(m_contents[m_offset + 0] == '\n'))
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                    for (size_t i2 = 0; i2 < 1; i2++)
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                }
                if (m_contents.length() > m_offset + 2 && m_contents[m_offset + 0] == '/' && m_contents[m_offset + 1] == '*')
                {
                    wasMatched1 = true;
                    for (size_t i3 = 0; i3 < 2; i3++)
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                    while (m_contents.length() > m_offset + 2 && !(m_contents[m_offset + 0] == '*' && m_contents[m_offset + 1] == '/'))
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                    for (size_t i3 = 0; i3 < 2; i3++)
                    {
                        switch (m_contents[m_offset])
                        {
                            case '\r':
                            case '\t':
                            case ' ': m_column++; m_offset++; break;
                            case '\n': m_line++; m_column = 1; m_offset++; break;
                            default: m_column++; m_offset++; break;
                        }
                    }
                }
                if (!wasMatched1)
                {
                    return;
                }
            }
        }
    }
}
void leaf::parsing::instance::report(std::string_view message, size_t depth)
{
    std::cout << "[L" << m_line << "]" << "[C" << m_column << "] " << message << "\n";
}
leaf::parsing::instance::token leaf::parsing::instance::create_token(size_t length, tok type)
{
    token t;
    t.file = m_file;
    t.line = m_line;
    t.column = m_column;
    t.offset = m_offset;
    t.length = length;
    t.type = type;
    for (auto i = 0; i < length; i++)
    {
        next();
    }
    return t;
}
std::shared_ptr<leaf::parsing::instance::main> leaf::parsing::instance::parse()
{
    skip();
    return p_match_main(0);
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute_arg_item_a> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute_arg_item_a:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute_arg_item_b> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute_arg_item_b:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute_args_a> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute_args_a:");
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute_args_b> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute_args_b:");
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute_item> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute_item:");
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    switch (node->args.index())
    {
        case 0:
        if (std::get<std::shared_ptr<attribute_args_a>>(node->args))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<attribute_args_a>>(node->args), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<attribute_args_b>>(node->args))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<attribute_args_b>>(node->args), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<attribute> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("attribute:");
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [items]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<scope> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("scope:");
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [usings]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->body)
    {
        switch (element.index())
        {
            case 0:
            if (std::get<std::shared_ptr<control_structure>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<control_structure>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
            case 1:
            if (std::get<std::shared_ptr<statement>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<statement>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<scope_getset> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("scope_getset:");
    if (node->get)
    {
        auto lines = create_string_tree(node->get, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [get]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->set)
    {
        auto lines = create_string_tree(node->set, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [set]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<control_structure_body> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("control_structure_body:");
    switch (node->body.index())
    {
        case 0:
        if (std::get<std::shared_ptr<scope>>(node->body))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<scope>>(node->body), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<control_structure>>(node->body))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<control_structure>>(node->body), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<statement>>(node->body))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<statement>>(node->body), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<while_loop> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("while_loop:");
    if (node->condition)
    {
        auto lines = create_string_tree(node->condition, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [condition]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<if_body> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("if_body:");
    if (node->condition)
    {
        auto lines = create_string_tree(node->condition, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [condition]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<else_body> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("else_body:");
    if (node->else_body)
    {
        auto lines = create_string_tree(node->else_body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [else_body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<if_else> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("if_else:");
    if (node->if_)
    {
        auto lines = create_string_tree(node->if_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [if_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->else_)
    {
        auto lines = create_string_tree(node->else_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [else_]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<switch_case> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("switch_case:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<switch_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("switch_:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    for (auto element : node->part)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [part]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->default_body)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [default_body]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragmas]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<assembly_terminate> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("assembly_terminate:");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<assembly> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("assembly:");
    for (auto element : node->args)
    {
        output.push_back(std::string("  ") + "token (L" + std::to_string(element.line) + "; C" + std::to_string(element.column) + "; O" + std::to_string(element.offset) + ") `" + std::string(contents.substr(element.offset, element.length).begin(), contents.substr(element.offset, element.length).end()) + "`");
    }
    for (auto element : node->opcode)
    {
        output.push_back(std::string("  ") + "token (L" + std::to_string(element.line) + "; C" + std::to_string(element.column) + "; O" + std::to_string(element.offset) + ") `" + std::string(contents.substr(element.offset, element.length).begin(), contents.substr(element.offset, element.length).end()) + "`");
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<control_structure> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("control_structure:");
    if (node->pragmas)
    {
        auto lines = create_string_tree(node->pragmas, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragmas]" "\u001b[0m" : line));
            first = false;
        }
    }
    switch (node->content.index())
    {
        case 0:
        if (std::get<std::shared_ptr<while_loop>>(node->content))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<while_loop>>(node->content), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [content]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<if_else>>(node->content))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<if_else>>(node->content), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [content]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<switch_>>(node->content))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<switch_>>(node->content), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [content]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 3:
        if (std::get<std::shared_ptr<scope>>(node->content))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<scope>>(node->content), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [content]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 4:
        if (std::get<std::shared_ptr<assembly>>(node->content))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<assembly>>(node->content), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [content]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_chain_start> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_chain_start:");
    if (node->part_alloc)
    {
        auto lines = create_string_tree(node->part_alloc, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [part_alloc]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->part_free)
    {
        auto lines = create_string_tree(node->part_free, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [part_free]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->part_call)
    {
        auto lines = create_string_tree(node->part_call, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [part_call]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->part_ident.line) + "; C" + std::to_string(node->part_ident.column) + "; O" + std::to_string(node->part_ident.offset) + ") `" + std::string(contents.substr(node->part_ident.offset, node->part_ident.length).begin(), contents.substr(node->part_ident.offset, node->part_ident.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_constant> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_constant:");
    if (node->typeof_)
    {
        auto lines = create_string_tree(node->typeof_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [typeof_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->nameof)
    {
        auto lines = create_string_tree(node->nameof, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [nameof]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->sizeof_)
    {
        auto lines = create_string_tree(node->sizeof_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [sizeof_]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->t.line) + "; C" + std::to_string(node->t.column) + "; O" + std::to_string(node->t.offset) + ") `" + std::string(contents.substr(node->t.offset, node->t.length).begin(), contents.substr(node->t.offset, node->t.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_value> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_value:");
    if (node->scalar)
    {
        auto lines = create_string_tree(node->scalar, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [scalar]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->integer_hex)
    {
        auto lines = create_string_tree(node->integer_hex, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [integer_hex]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->integer_binary)
    {
        auto lines = create_string_tree(node->integer_binary, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [integer_binary]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->integer)
    {
        auto lines = create_string_tree(node->integer, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [integer]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->character)
    {
        auto lines = create_string_tree(node->character, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [character]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->string)
    {
        auto lines = create_string_tree(node->string, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [string]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->constant)
    {
        auto lines = create_string_tree(node->constant, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [constant]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_nullar> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_nullar:");
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<expression>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<expression>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_chain>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_chain>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<exp_value>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_value>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_unary> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_unary:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_unary>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_unary>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_nullar>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_nullar>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    if (node->cast_target)
    {
        auto lines = create_string_tree(node->cast_target, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [cast_target]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<expression> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("expression:");
    if (node->assign_to)
    {
        auto lines = create_string_tree(node->assign_to, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [assign_to]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->exp)
    {
        auto lines = create_string_tree(node->exp, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [exp]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<encapsulation> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("encapsulation:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->tok.line) + "; C" + std::to_string(node->tok.column) + "; O" + std::to_string(node->tok.offset) + ") `" + std::string(contents.substr(node->tok.offset, node->tok.length).begin(), contents.substr(node->tok.offset, node->tok.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<namespace_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("namespace_:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->name)
    {
        auto lines = create_string_tree(node->name, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [name]" "\u001b[0m" : line));
            first = false;
        }
    }
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [usings]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->namespaces)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [namespaces]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [conversions]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [classes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [methods]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [properties]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [fields]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragmas]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<class_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("class_:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->scope)
    {
        auto lines = create_string_tree(node->scope, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [scope]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [usings]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->indexers)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [indexers]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->operators_binary)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [operators_binary]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->operators_unary)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [operators_unary]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [conversions]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [classes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->constructors)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [constructors]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->destructors)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [destructors]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->copystructors)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [copystructors]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [properties]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [fields]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [methods]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragmas]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<method_arglist_item_with_default> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("method_arglist_item_with_default:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->type)
    {
        auto lines = create_string_tree(node->type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<method_arglist_item> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("method_arglist_item:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->type)
    {
        auto lines = create_string_tree(node->type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<method_arglist> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("method_arglist:");
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<method_arglist_indexer> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("method_arglist_indexer:");
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<method> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("method:");
    if (node->is_sealed.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_sealed.value()));
    }
    if (node->is_virtual.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_virtual.value()));
    }
    if (node->is_static.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_static.value()));
    }
    if (node->is_inline.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_inline.value()));
    }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->return_type)
    {
        auto lines = create_string_tree(node->return_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [return_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->arglist)
    {
        auto lines = create_string_tree(node->arglist, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [arglist]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<constructor> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("constructor:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->arglist)
    {
        auto lines = create_string_tree(node->arglist, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [arglist]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<destructor> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("destructor:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->arglist)
    {
        auto lines = create_string_tree(node->arglist, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [arglist]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<copystructor> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("copystructor:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->arglist)
    {
        auto lines = create_string_tree(node->arglist, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [arglist]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<conversion> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("conversion:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->source_type)
    {
        auto lines = create_string_tree(node->source_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [source_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<indexer> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("indexer:");
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->arglist)
    {
        auto lines = create_string_tree(node->arglist, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [arglist]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<operator_binary_overload> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("operator_binary_overload:");
    if (node->is_inline.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_inline.value()));
    }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->left)
    {
        auto lines = create_string_tree(node->left, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<operator_unary_overload> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("operator_unary_overload:");
    if (node->is_inline.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_inline.value()));
    }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<property> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("property:");
    if (node->is_sealed.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_sealed.value()));
    }
    if (node->is_virtual.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_virtual.value()));
    }
    if (node->is_static.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_static.value()));
    }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<field> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("field:");
    if (node->is_sealed.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_sealed.value()));
    }
    if (node->is_virtual.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_virtual.value()));
    }
    if (node->is_static.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_static.value()));
    }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [attributes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    if (node->encaps)
    {
        auto lines = create_string_tree(node->encaps, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [encaps]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->target_type)
    {
        auto lines = create_string_tree(node->target_type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [target_type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<using_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("using_:");
    if (node->is_namespace.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_namespace.value()));
    }
    if (node->is_class.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_class.value()));
    }
    if (node->ident)
    {
        auto lines = create_string_tree(node->ident, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [ident]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->alias.line) + "; C" + std::to_string(node->alias.column) + "; O" + std::to_string(node->alias.offset) + ") `" + std::string(contents.substr(node->alias.offset, node->alias.length).begin(), contents.substr(node->alias.offset, node->alias.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<call> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("call:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->method.line) + "; C" + std::to_string(node->method.column) + "; O" + std::to_string(node->method.offset) + ") `" + std::string(contents.substr(node->method.offset, node->method.length).begin(), contents.substr(node->method.offset, node->method.length).end()) + "`");
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<call_body> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("call_body:");
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [args]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<free> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("free:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<alloc> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("alloc:");
    if (node->is_stack.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_stack.value()));
    }
    if (node->is_heap.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_heap.value()));
    }
    if (node->type)
    {
        auto lines = create_string_tree(node->type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [type]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->exp)
    {
        auto lines = create_string_tree(node->exp, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [exp]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->body)
    {
        auto lines = create_string_tree(node->body, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [body]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<template_usage_item> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("template_usage_item:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->key.line) + "; C" + std::to_string(node->key.column) + "; O" + std::to_string(node->key.offset) + ") `" + std::string(contents.substr(node->key.offset, node->key.length).begin(), contents.substr(node->key.offset, node->key.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<template_usage> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("template_usage:");
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [items]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<template_definition_item> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("template_definition_item:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->key.line) + "; C" + std::to_string(node->key.column) + "; O" + std::to_string(node->key.offset) + ") `" + std::string(contents.substr(node->key.offset, node->key.length).begin(), contents.substr(node->key.offset, node->key.length).end()) + "`");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<template_definition> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("template_definition:");
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [items]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<typeof_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("typeof_:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<nameof> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("nameof:");
    if (node->value)
    {
        auto lines = create_string_tree(node->value, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<sizeof_> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("sizeof_:");
    if (node->type)
    {
        auto lines = create_string_tree(node->type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [type]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<type_match> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("type_match:");
    if (node->is_array.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_array.value()));
    }
    if (node->is_heap.has_value())
    {
        output.push_back(std::string("  ") + std::to_string(node->is_heap.value()));
    }
    if (node->base)
    {
        auto lines = create_string_tree(node->base, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [base]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<string_formatable> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("string_formatable:");
    for (auto element : node->parts)
    {
        switch (element.index())
        {
            case 0:
            output.push_back(std::string("  ") + "token (L" + std::to_string(std::get<token>(element).line) + "; C" + std::to_string(std::get<token>(element).column) + "; O" + std::to_string(std::get<token>(element).offset) + ") `" + std::string(contents.substr(std::get<token>(element).offset, std::get<token>(element).length).begin(), contents.substr(std::get<token>(element).offset, std::get<token>(element).length).end()) + "`");
            break;
            case 1:
            if (std::get<std::shared_ptr<expression>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<expression>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [parts]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<string_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("string_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<string_formatable>>(node->value))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<string_formatable>>(node->value), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [value]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        output.push_back(std::string("  ") + "token (L" + std::to_string(std::get<token>(node->value).line) + "; C" + std::to_string(std::get<token>(node->value).column) + "; O" + std::to_string(std::get<token>(node->value).offset) + ") `" + std::string(contents.substr(std::get<token>(node->value).offset, std::get<token>(node->value).length).begin(), contents.substr(std::get<token>(node->value).offset, std::get<token>(node->value).length).end()) + "`");
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<scalar_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("scalar_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->value.line) + "; C" + std::to_string(node->value.column) + "; O" + std::to_string(node->value.offset) + ") `" + std::string(contents.substr(node->value.offset, node->value.length).begin(), contents.substr(node->value.offset, node->value.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<integer_hex_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("integer_hex_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->value.line) + "; C" + std::to_string(node->value.column) + "; O" + std::to_string(node->value.offset) + ") `" + std::string(contents.substr(node->value.offset, node->value.length).begin(), contents.substr(node->value.offset, node->value.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<integer_binary_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("integer_binary_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->value.line) + "; C" + std::to_string(node->value.column) + "; O" + std::to_string(node->value.offset) + ") `" + std::string(contents.substr(node->value.offset, node->value.length).begin(), contents.substr(node->value.offset, node->value.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<integer_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("integer_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->value.line) + "; C" + std::to_string(node->value.column) + "; O" + std::to_string(node->value.offset) + ") `" + std::string(contents.substr(node->value.offset, node->value.length).begin(), contents.substr(node->value.offset, node->value.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<char_literal> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("char_literal:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->prefix.line) + "; C" + std::to_string(node->prefix.column) + "; O" + std::to_string(node->prefix.offset) + ") `" + std::string(contents.substr(node->prefix.offset, node->prefix.length).begin(), contents.substr(node->prefix.offset, node->prefix.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->value.line) + "; C" + std::to_string(node->value.column) + "; O" + std::to_string(node->value.offset) + ") `" + std::string(contents.substr(node->value.offset, node->value.length).begin(), contents.substr(node->value.offset, node->value.length).end()) + "`");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->postfix.line) + "; C" + std::to_string(node->postfix.column) + "; O" + std::to_string(node->postfix.offset) + ") `" + std::string(contents.substr(node->postfix.offset, node->postfix.length).begin(), contents.substr(node->postfix.offset, node->postfix.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<declaration> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("declaration:");
    if (node->type)
    {
        auto lines = create_string_tree(node->type, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [type]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->name.line) + "; C" + std::to_string(node->name.column) + "; O" + std::to_string(node->name.offset) + ") `" + std::string(contents.substr(node->name.offset, node->name.length).begin(), contents.substr(node->name.offset, node->name.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<statement> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("statement:");
    if (node->ret)
    {
        auto lines = create_string_tree(node->ret, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [ret]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->fwrd_decl)
    {
        auto lines = create_string_tree(node->fwrd_decl, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [fwrd_decl]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->exp)
    {
        auto lines = create_string_tree(node->exp, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [exp]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->pragma)
    {
        auto lines = create_string_tree(node->pragma, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragma]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<pragma> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("pragma:");
    for (auto element : node->contents)
    {
        switch (element.index())
        {
            case 0:
            if (std::get<std::shared_ptr<pragma_disable>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<pragma_disable>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [contents]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
            case 1:
            if (std::get<std::shared_ptr<pragma_enable>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<pragma_enable>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [contents]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
            case 2:
            if (std::get<std::shared_ptr<pragma_size>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<pragma_size>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [contents]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
            case 3:
            if (std::get<std::shared_ptr<pragma_align>>(element))
            {
                auto lines = create_string_tree(std::get<std::shared_ptr<pragma_align>>(element), contents);
                bool first = true;
                for (auto line : lines)
                {
                    output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [contents]" "\u001b[0m" : line));
                    first = false;
                }
            }
            break;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<pragma_align> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("pragma_align:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->bytes.line) + "; C" + std::to_string(node->bytes.column) + "; O" + std::to_string(node->bytes.offset) + ") `" + std::string(contents.substr(node->bytes.offset, node->bytes.length).begin(), contents.substr(node->bytes.offset, node->bytes.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<pragma_size> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("pragma_size:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->bytes.line) + "; C" + std::to_string(node->bytes.column) + "; O" + std::to_string(node->bytes.offset) + ") `" + std::string(contents.substr(node->bytes.offset, node->bytes.length).begin(), contents.substr(node->bytes.offset, node->bytes.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<pragma_disable> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("pragma_disable:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->code.line) + "; C" + std::to_string(node->code.column) + "; O" + std::to_string(node->code.offset) + ") `" + std::string(contents.substr(node->code.offset, node->code.length).begin(), contents.substr(node->code.offset, node->code.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<pragma_enable> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("pragma_enable:");
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->code.line) + "; C" + std::to_string(node->code.column) + "; O" + std::to_string(node->code.offset) + ") `" + std::string(contents.substr(node->code.offset, node->code.length).begin(), contents.substr(node->code.offset, node->code.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<main> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("main:");
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [usings]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->namespaces)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [namespaces]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [conversions]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [classes]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [methods]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [properties]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [fields]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = create_string_tree(element, contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [pragmas]" "\u001b[0m" : line));
                first = false;
            }
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_chain> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_chain:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_chain>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_chain>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_chain_start>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_chain_start>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    if (node->chain_call)
    {
        auto lines = create_string_tree(node->chain_call, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [chain_call]" "\u001b[0m" : line));
            first = false;
        }
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->chain_access.line) + "; C" + std::to_string(node->chain_access.column) + "; O" + std::to_string(node->chain_access.offset) + ") `" + std::string(contents.substr(node->chain_access.offset, node->chain_access.length).begin(), contents.substr(node->chain_access.offset, node->chain_access.length).end()) + "`");
    if (node->chain_indexer)
    {
        auto lines = create_string_tree(node->chain_indexer, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [chain_indexer]" "\u001b[0m" : line));
            first = false;
        }
    }
    if (node->chain_template)
    {
        auto lines = create_string_tree(node->chain_template, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [chain_template]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_binary_4> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_binary_4:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_4>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_4>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_unary>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_unary>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_binary_3> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_binary_3:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_3>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_3>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_4>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_4>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_binary_2> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_binary_2:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_2>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_2>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_3>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_3>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_binary_1> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_binary_1:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_1>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_1>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_2>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_2>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_arithmetic_2> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_arithmetic_2:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_arithmetic_2>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_arithmetic_2>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_1>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_binary_1>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_arithmetic_1> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_arithmetic_1:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_arithmetic_1>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_arithmetic_1>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_arithmetic_2>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_arithmetic_2>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_compare> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_compare:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_compare>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_compare>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_arithmetic_1>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_arithmetic_1>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_equality> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_equality:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_equality>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_equality>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_compare>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_compare>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_and> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_and:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_and>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_and>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_equality>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_equality>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<exp_or> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("exp_or:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_or>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_or>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_and>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<exp_and>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->operator_.line) + "; C" + std::to_string(node->operator_.column) + "; O" + std::to_string(node->operator_.offset) + ") `" + std::string(contents.substr(node->operator_.offset, node->operator_.length).begin(), contents.substr(node->operator_.offset, node->operator_.length).end()) + "`");
    if (node->right)
    {
        auto lines = create_string_tree(node->right, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [right]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<ident_navigation> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("ident_navigation:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<ident_navigation>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<ident_navigation>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        output.push_back(std::string("  ") + "token (L" + std::to_string(std::get<token>(node->left).line) + "; C" + std::to_string(std::get<token>(node->left).column) + "; O" + std::to_string(std::get<token>(node->left).offset) + ") `" + std::string(contents.substr(std::get<token>(node->left).offset, std::get<token>(node->left).length).begin(), contents.substr(std::get<token>(node->left).offset, std::get<token>(node->left).length).end()) + "`");
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->right.line) + "; C" + std::to_string(node->right.column) + "; O" + std::to_string(node->right.offset) + ") `" + std::string(contents.substr(node->right.offset, node->right.length).begin(), contents.substr(node->right.offset, node->right.length).end()) + "`");
    return output;
}
std::vector<std::string> leaf::parsing::instance::create_string_tree(std::shared_ptr<type_navigation> node, std::string_view contents)
{
    std::vector<std::string> output;
    output.push_back("type_navigation:");
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<type_navigation>>(node->left))
        {
            auto lines = create_string_tree(std::get<std::shared_ptr<type_navigation>>(node->left), contents);
            bool first = true;
            for (auto line : lines)
            {
                output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [left]" "\u001b[0m" : line));
                first = false;
            }
        }
        break;
        case 1:
        output.push_back(std::string("  ") + "token (L" + std::to_string(std::get<token>(node->left).line) + "; C" + std::to_string(std::get<token>(node->left).column) + "; O" + std::to_string(std::get<token>(node->left).offset) + ") `" + std::string(contents.substr(std::get<token>(node->left).offset, std::get<token>(node->left).length).begin(), contents.substr(std::get<token>(node->left).offset, std::get<token>(node->left).length).end()) + "`");
        break;
    }
    output.push_back(std::string("  ") + "token (L" + std::to_string(node->right.line) + "; C" + std::to_string(node->right.column) + "; O" + std::to_string(node->right.offset) + ") `" + std::string(contents.substr(node->right.offset, node->right.length).begin(), contents.substr(node->right.offset, node->right.length).end()) + "`");
    if (node->template_)
    {
        auto lines = create_string_tree(node->template_, contents);
        bool first = true;
        for (auto line : lines)
        {
            output.push_back((first ? std::string("- ") : std::string("  ")) + (first ? line + "\u001b[30;1m" " [template_]" "\u001b[0m" : line));
            first = false;
        }
    }
    return output;
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute_arg_item_a> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute_arg_item_b> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute_args_a> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute_args_b> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute_item> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    switch (node->args.index())
    {
        case 0:
        if (std::get<std::shared_ptr<attribute_args_a>>(node->args))
        {
            auto lines = visit(std::get<std::shared_ptr<attribute_args_a>>(node->args));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<attribute_args_b>>(node->args))
        {
            auto lines = visit(std::get<std::shared_ptr<attribute_args_b>>(node->args));
        }
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<attribute> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<scope> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->body)
    {
        switch (element.index())
        {
            case 0:
            if (std::get<std::shared_ptr<control_structure>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<control_structure>>(element));
            }
            break;
            case 1:
            if (std::get<std::shared_ptr<statement>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<statement>>(element));
            }
            break;
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<scope_getset> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->get)
    {
        auto lines = visit(node->get);
    }
    if (node->set)
    {
        auto lines = visit(node->set);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<control_structure_body> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->body.index())
    {
        case 0:
        if (std::get<std::shared_ptr<scope>>(node->body))
        {
            auto lines = visit(std::get<std::shared_ptr<scope>>(node->body));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<control_structure>>(node->body))
        {
            auto lines = visit(std::get<std::shared_ptr<control_structure>>(node->body));
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<statement>>(node->body))
        {
            auto lines = visit(std::get<std::shared_ptr<statement>>(node->body));
        }
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<while_loop> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->condition)
    {
        auto lines = visit(node->condition);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<if_body> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->condition)
    {
        auto lines = visit(node->condition);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<else_body> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->else_body)
    {
        auto lines = visit(node->else_body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<if_else> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->if_)
    {
        auto lines = visit(node->if_);
    }
    if (node->else_)
    {
        auto lines = visit(node->else_);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<switch_case> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<switch_> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    for (auto element : node->part)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->default_body)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<assembly_terminate> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<assembly> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
    }
    for (auto element : node->opcode)
    {
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<control_structure> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->pragmas)
    {
        auto lines = visit(node->pragmas);
    }
    switch (node->content.index())
    {
        case 0:
        if (std::get<std::shared_ptr<while_loop>>(node->content))
        {
            auto lines = visit(std::get<std::shared_ptr<while_loop>>(node->content));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<if_else>>(node->content))
        {
            auto lines = visit(std::get<std::shared_ptr<if_else>>(node->content));
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<switch_>>(node->content))
        {
            auto lines = visit(std::get<std::shared_ptr<switch_>>(node->content));
        }
        break;
        case 3:
        if (std::get<std::shared_ptr<scope>>(node->content))
        {
            auto lines = visit(std::get<std::shared_ptr<scope>>(node->content));
        }
        break;
        case 4:
        if (std::get<std::shared_ptr<assembly>>(node->content))
        {
            auto lines = visit(std::get<std::shared_ptr<assembly>>(node->content));
        }
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_chain_start> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->part_alloc)
    {
        auto lines = visit(node->part_alloc);
    }
    if (node->part_free)
    {
        auto lines = visit(node->part_free);
    }
    if (node->part_call)
    {
        auto lines = visit(node->part_call);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_constant> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->typeof_)
    {
        auto lines = visit(node->typeof_);
    }
    if (node->nameof)
    {
        auto lines = visit(node->nameof);
    }
    if (node->sizeof_)
    {
        auto lines = visit(node->sizeof_);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_value> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->scalar)
    {
        auto lines = visit(node->scalar);
    }
    if (node->integer_hex)
    {
        auto lines = visit(node->integer_hex);
    }
    if (node->integer_binary)
    {
        auto lines = visit(node->integer_binary);
    }
    if (node->integer)
    {
        auto lines = visit(node->integer);
    }
    if (node->character)
    {
        auto lines = visit(node->character);
    }
    if (node->string)
    {
        auto lines = visit(node->string);
    }
    if (node->constant)
    {
        auto lines = visit(node->constant);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_nullar> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<expression>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<expression>>(node->value));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_chain>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_chain>>(node->value));
        }
        break;
        case 2:
        if (std::get<std::shared_ptr<exp_value>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_value>>(node->value));
        }
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_unary> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_unary>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_unary>>(node->value));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_nullar>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_nullar>>(node->value));
        }
        break;
    }
    if (node->cast_target)
    {
        auto lines = visit(node->cast_target);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<expression> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->assign_to)
    {
        auto lines = visit(node->assign_to);
    }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    if (node->exp)
    {
        auto lines = visit(node->exp);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<encapsulation> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<namespace_> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->name)
    {
        auto lines = visit(node->name);
    }
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->namespaces)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<class_> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->scope)
    {
        auto lines = visit(node->scope);
    }
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->indexers)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->operators_binary)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->operators_unary)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->constructors)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->destructors)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->copystructors)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<method_arglist_item_with_default> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->type)
    {
        auto lines = visit(node->type);
    }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<method_arglist_item> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->type)
    {
        auto lines = visit(node->type);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<method_arglist> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<method_arglist_indexer> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<method> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->return_type)
    {
        auto lines = visit(node->return_type);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->arglist)
    {
        auto lines = visit(node->arglist);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<constructor> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->arglist)
    {
        auto lines = visit(node->arglist);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<destructor> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->arglist)
    {
        auto lines = visit(node->arglist);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<copystructor> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->arglist)
    {
        auto lines = visit(node->arglist);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<conversion> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    if (node->source_type)
    {
        auto lines = visit(node->source_type);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<indexer> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->arglist)
    {
        auto lines = visit(node->arglist);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<operator_binary_overload> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->left)
    {
        auto lines = visit(node->left);
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<operator_unary_overload> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<property> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<field> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->attributes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    if (node->encaps)
    {
        auto lines = visit(node->encaps);
    }
    if (node->target_type)
    {
        auto lines = visit(node->target_type);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<using_> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->ident)
    {
        auto lines = visit(node->ident);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<call> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<call_body> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->args)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<free> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<alloc> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->type)
    {
        auto lines = visit(node->type);
    }
    if (node->exp)
    {
        auto lines = visit(node->exp);
    }
    if (node->body)
    {
        auto lines = visit(node->body);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<template_usage_item> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<template_usage> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<template_definition_item> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<template_definition> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->items)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<typeof_> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<nameof> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->value)
    {
        auto lines = visit(node->value);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<sizeof_> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->type)
    {
        auto lines = visit(node->type);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<type_match> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->base)
    {
        auto lines = visit(node->base);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<string_formatable> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->parts)
    {
        switch (element.index())
        {
            case 0:
            break;
            case 1:
            if (std::get<std::shared_ptr<expression>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<expression>>(element));
            }
            break;
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<string_literal> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->value.index())
    {
        case 0:
        if (std::get<std::shared_ptr<string_formatable>>(node->value))
        {
            auto lines = visit(std::get<std::shared_ptr<string_formatable>>(node->value));
        }
        break;
        case 1:
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<scalar_literal> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<integer_hex_literal> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<integer_binary_literal> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<integer_literal> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<char_literal> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<declaration> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->type)
    {
        auto lines = visit(node->type);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<statement> node)
{
    if (!visit_enter(node)) { return false; }
    if (node->ret)
    {
        auto lines = visit(node->ret);
    }
    if (node->fwrd_decl)
    {
        auto lines = visit(node->fwrd_decl);
    }
    if (node->exp)
    {
        auto lines = visit(node->exp);
    }
    if (node->pragma)
    {
        auto lines = visit(node->pragma);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<pragma> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->contents)
    {
        switch (element.index())
        {
            case 0:
            if (std::get<std::shared_ptr<pragma_disable>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<pragma_disable>>(element));
            }
            break;
            case 1:
            if (std::get<std::shared_ptr<pragma_enable>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<pragma_enable>>(element));
            }
            break;
            case 2:
            if (std::get<std::shared_ptr<pragma_size>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<pragma_size>>(element));
            }
            break;
            case 3:
            if (std::get<std::shared_ptr<pragma_align>>(element))
            {
                auto lines = visit(std::get<std::shared_ptr<pragma_align>>(element));
            }
            break;
        }
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<pragma_align> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<pragma_size> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<pragma_disable> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<pragma_enable> node)
{
    if (!visit_enter(node)) { return false; }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_chain> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_chain>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_chain>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_chain_start>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_chain_start>>(node->left));
        }
        break;
    }
    if (node->chain_call)
    {
        auto lines = visit(node->chain_call);
    }
    if (node->chain_indexer)
    {
        auto lines = visit(node->chain_indexer);
    }
    if (node->chain_template)
    {
        auto lines = visit(node->chain_template);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_binary_4> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_4>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_4>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_unary>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_unary>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_binary_3> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_3>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_3>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_4>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_4>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_binary_2> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_2>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_2>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_3>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_3>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_binary_1> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_binary_1>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_1>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_2>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_2>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_arithmetic_2> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_arithmetic_2>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_arithmetic_2>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_binary_1>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_binary_1>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_arithmetic_1> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_arithmetic_1>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_arithmetic_1>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_arithmetic_2>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_arithmetic_2>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_compare> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_compare>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_compare>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_arithmetic_1>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_arithmetic_1>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_equality> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_equality>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_equality>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_compare>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_compare>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_and> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_and>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_and>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_equality>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_equality>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<exp_or> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<exp_or>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_or>>(node->left));
        }
        break;
        case 1:
        if (std::get<std::shared_ptr<exp_and>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<exp_and>>(node->left));
        }
        break;
    }
    if (node->right)
    {
        auto lines = visit(node->right);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<ident_navigation> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<ident_navigation>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<ident_navigation>>(node->left));
        }
        break;
        case 1:
        break;
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<type_navigation> node)
{
    if (!visit_enter(node)) { return false; }
    switch (node->left.index())
    {
        case 0:
        if (std::get<std::shared_ptr<type_navigation>>(node->left))
        {
            auto lines = visit(std::get<std::shared_ptr<type_navigation>>(node->left));
        }
        break;
        case 1:
        break;
    }
    if (node->template_)
    {
        auto lines = visit(node->template_);
    }
    return visit_leave(node);
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute_arg_item_a> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute_arg_item_b> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute_args_a> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute_args_b> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<attribute> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<scope> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<scope_getset> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<control_structure_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<while_loop> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<if_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<else_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<if_else> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<switch_case> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<switch_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<assembly_terminate> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<assembly> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<control_structure> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_chain_start> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_constant> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_value> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_nullar> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_unary> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<expression> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<encapsulation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<namespace_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<class_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<method_arglist_item_with_default> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<method_arglist_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<method_arglist> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<method_arglist_indexer> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<method> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<constructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<destructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<copystructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<conversion> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<indexer> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<operator_binary_overload> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<operator_unary_overload> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<property> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<field> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<using_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<call> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<call_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<free> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<alloc> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<template_usage_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<template_usage> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<template_definition_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<template_definition> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<typeof_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<nameof> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<sizeof_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<type_match> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<string_formatable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<string_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<scalar_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<integer_hex_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<integer_binary_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<integer_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<char_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<declaration> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<statement> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<pragma> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<pragma_align> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<pragma_size> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<pragma_disable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<pragma_enable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<main> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_chain> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_binary_4> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_binary_3> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_binary_2> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_binary_1> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_arithmetic_2> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_arithmetic_1> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_compare> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_equality> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_and> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<exp_or> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<ident_navigation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_enter(std::shared_ptr<type_navigation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute_arg_item_a> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute_arg_item_b> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute_args_a> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute_args_b> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<attribute> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<scope> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<scope_getset> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<control_structure_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<while_loop> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<if_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<else_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<if_else> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<switch_case> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<switch_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<assembly_terminate> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<assembly> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<control_structure> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_chain_start> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_constant> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_value> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_nullar> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_unary> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<expression> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<encapsulation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<namespace_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<class_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<method_arglist_item_with_default> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<method_arglist_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<method_arglist> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<method_arglist_indexer> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<method> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<constructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<destructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<copystructor> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<conversion> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<indexer> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<operator_binary_overload> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<operator_unary_overload> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<property> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<field> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<using_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<call> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<call_body> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<free> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<alloc> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<template_usage_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<template_usage> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<template_definition_item> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<template_definition> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<typeof_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<nameof> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<sizeof_> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<type_match> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<string_formatable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<string_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<scalar_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<integer_hex_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<integer_binary_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<integer_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<char_literal> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<declaration> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<statement> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<pragma> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<pragma_align> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<pragma_size> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<pragma_disable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<pragma_enable> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<main> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_chain> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_binary_4> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_binary_3> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_binary_2> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_binary_1> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_arithmetic_2> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_arithmetic_1> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_compare> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_equality> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_and> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<exp_or> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<ident_navigation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit_leave(std::shared_ptr<type_navigation> node)
{
    return true;
}
bool leaf::parsing::instance::visitor::visit(std::shared_ptr<main> node)
{
    if (!visit_enter(node)) { return false; }
    for (auto element : node->usings)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->namespaces)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->conversions)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->classes)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->methods)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->properties)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->fields)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    for (auto element : node->pragmas)
    {
        if (element)
        {
            auto lines = visit(element);
        }
    }
    return visit_leave(node);
}
