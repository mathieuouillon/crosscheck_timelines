#pragma once

// C++ headers
#include <limits>

// toml headers
#include <toml++/toml.h>

// Project headers
#include <Plotting/Draw.hpp>
#include <electron_normalized_FD_yields/Histograms.hpp>

namespace electron_normalized_FD_yields {
class Drawing {

   private:
    // ****** private members
    Histograms& m_histograms;

   public:
    // ****** constructors and destructor
    explicit Drawing(Histograms& histograms);

    // ****** public methods
    auto draw_timelines() -> void;
};

}  // namespace electron_normalized_FD_yields