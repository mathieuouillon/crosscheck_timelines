# check_timelines

A C++ analysis that builds **run-quality "timelines"** for CLAS12 Run Group D: per-run physics quantities plotted versus run number so that outlier / bad runs stand out. For every run it opens the skimmed HIPO files, counts trigger electrons (Forward Detector, per sector s1–s6 and combined) plus π+, π−, π0 and ρ0 candidates, and **normalizes each yield by the accumulated beam charge** — so a stable-quality timeline is flat.

Inputs: HIPO skims from `/cache/hallb/scratch/rg-d/production/skim_pass0v11/{LD2,CxC,CuSn,ShortEmpRand}/`, the per-run charge table `run_numbers_with_charge.toml`, cut values in `config/study1.toml`, and hardcoded run lists in `include/Core/Runs.hpp`. Output: ROOT `TGraphErrors` timelines saved to `plots/` in `C/`, `pdf/`, `root/`, `tex/` (e.g. `graph_normalized_electron_yield_all`, `graph_normalized_charge_all`, `graph_{pip,pi0,rho0}_yield_all`).

## Build & run

**C++23, meson + ninja.** Deps: `fmt`, `tomlplusplus`, `lz4` (meson wraps), vendored `hipo4/` (via `subdir('hipo4')`), and ROOT (via `root-config`).

```bash
meson setup build
meson compile -C build
cd build && ./crosscheck-timelines     # run from build/: main.cpp uses ../run_numbers_with_charge.toml and ../plots/
```

## Key files

- `src/main.cpp` — entry point; gathers per-target run-file lists, parses the charge TOML, runs `multithread_reader(reader, runs, 40)`, then `Drawing::draw_timelines()`.
- `src/electron_normalized_FD_yields/Reader.cpp` — per-run HIPO loop: vz cuts, e/π±/π0/ρ0 selection, charge normalization, fills the per-sector graphs.
- `src/electron_normalized_FD_yields/Drawing.cpp` — draws + saves the timeline graphs.
- `include/electron_normalized_FD_yields/Histograms.hpp` — the `TThreadedObject<TGraphErrors>` timeline objects.
- `include/Core/Runs.hpp` — inbending/outbending run-number lists per target.
- `include/thread_pool/` — vendored BS::thread_pool + `multithread_reader`.
- `config/study1.toml` — electron vz / chi2 cut ranges.
- `run_numbers_with_charge.toml` — per-run `[nb_files, accumulated_charge]` (the normalization denominator).
- `hipo4/` — vendored HIPO library (build dependency, keep).

## Notes

- Cleaned up (2026-07-20): removed `build/` **and** a redundant `builddir/`, `.cache/`, `plots/`, and the extracted meson deps under `subprojects/` (kept the `.wrap` files). Rebuild with the commands above.
- ⚠️ `subprojects/` also contains a **misplaced separate project** — `project('rgd-pi0', …)` with its own `src/`/`include/`/built output. It is unrelated to check_timelines (meson ignores it) — consider moving it out to `RGD/rgd_pi0/` as its own project.
