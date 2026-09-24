# Testbenches

I keep unit tests under `unit/`, full-design tests under `integration/`, and
small checked-in vectors under `data/`. Generated binaries and waveforms go to
the ignored `build/` directory or a temporary directory.

The first integration test is a direct copy of my M4 testbench. It preserves
the 16/16 numerical reference result and also records the known `DONE=NO`
behavior. I will tighten this test as I fix the controller.
