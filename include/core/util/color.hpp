
// external
#include <cstdint>

// internal


namespace brundolfEngine {
  namespace core {
    namespace util {

      struct Color {
      public:
        Color() {
          this->red = 255;
          this->green = 255;
          this->blue = 255;
          this->alpha = 255;
        }
        Color(uint8_t red, uint8_t green, uint8_t blue) {
          this->red = red;
          this->green = green;
          this->blue = blue;
          this->alpha = 255;
        }
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
          this->red = red;
          this->green = green;
          this->blue = blue;
          this->alpha = alpha;
        }

        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
      };

    }
  }
}
