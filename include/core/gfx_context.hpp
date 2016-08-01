#ifndef __gfx_context_hpp__
#define __gfx_context_hpp__

// external


// internal


namespace brundolfEngine {
  namespace core {

    class GfxContext {

    public:
      virtual ~GfxContext() { };

      // hooks
      virtual void initialize() = 0;
      virtual void refresh() = 0;
      virtual void quit() = 0;

    };

  }
}

#endif
