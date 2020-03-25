#include "stdstream.h"

#include "drivers/console.h"

static void stdoutPush(Stream *stream, uint8_t *data, size_t count)
{
    for (size_t i = 0; i < count; ++i)
        consolePut(data[i]);
}

static void stderrPush(Stream *stream, uint8_t *data, size_t count)
{
    // TODO : Change format
    for (size_t i = 0; i < count; ++i)
        consolePut(data[i]);
}

Stream stdoutStream = {
    .push = stdoutPush
};

Stream stderrStream = {
    .push = stderrPush
};
