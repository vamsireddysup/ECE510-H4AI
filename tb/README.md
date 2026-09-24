# Testbenches

I keep unit tests under `unit/`, full-design tests under `integration/`, and
small checked-in vectors under `data/`. Generated binaries and waveforms go to
the ignored `build/` directory or a temporary directory.

The first integration test started as a copy of my M4 testbench. It preserves
the 16/16 numerical reference result and now also requires `DONE=YES` and the
correct tile count.
