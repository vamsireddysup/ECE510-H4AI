# Stream protocol version history

This table explains why eight protocol numbers appear in results and tests. Read
the current wire contract in [stream protocol](stream-protocol.md); this page is
only the compatibility history.

| Version | Scale format | K movement | Status |
| ---: | --- | --- | --- |
| 1 | One FP32 scale per complete Q or K row (`Bs=D_HEAD`) | Reload each K tile for every Q tile row | Historical row-scale baseline; no longer emitted |
| 2 | One FP32 scale per complete row | Load K once into a command-level register cache | Historical K-reuse experiment; no longer emitted |
| 3 | One FP32 scale per 32 reduction elements | Reload K tiles | Tested compatibility build |
| 4 | One FP32 scale per 32 reduction elements | Load K once into a command-level register cache | Tested compatibility experiment |
| 5 | One FP32 scale per 16 reduction elements | Reload K tiles | Current default |
| 6 | One FP32 scale per 16 reduction elements | Load K once into a command-level register cache | Optional current experiment |
| 7 | One packed E4M3 scale per 16 reduction elements | Reload K tiles | Selectable, tested build |
| 8 | One packed E4M3 scale per 16 reduction elements | Load K once into a command-level register cache | Selectable, tested experiment |

Odd versions reload K and even versions reuse K. Versions 3 through 6 pack two
FP32 scales per 64-bit beat. Versions 7 and 8 pack eight E4M3 scale bytes per
beat. All versions pack 16 FP4 data values per beat. Register `0x1C` reports
the compiled version, so software can reject a mismatched packet format.

## Related

- [Current stream contract](stream-protocol.md)
- [ADR 0002: K reload default](adr/0002-k-reload-is-the-default.md)
- [ADR 0004: 1x16 scales](adr/0004-use-1x16-fp32-scales.md)
- [Architecture](architecture.md)
