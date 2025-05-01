#pragma once

namespace Plotting {

struct LineOpt {
    int16_t color = Color::kRed;
    int8_t width = 1;
};

inline auto
draw_vertical_line(double value, double max, const LineOpt& opt) -> std::unique_ptr<TLine> {

    auto line = std::make_unique<TLine>(value, 0, value, max);
    line->SetLineColor(opt.color);
    line->SetLineWidth(opt.width);
    line->Draw();

    return line;
}

}  // namespace Plotting