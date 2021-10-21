#include "yacpm_test_lib.h"

glm::vec2 do_math(const glm::vec2 &a, const glm::vec2 &b) {
    return glm::dot(a, b) - b
}
