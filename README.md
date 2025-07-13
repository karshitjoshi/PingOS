# PingOS


https://github.com/user-attachments/assets/5aedc40c-ab85-4687-995c-ffc405e49e26


**PingOS** is a minimalist hobbyist operating system built for the **x86_64 architecture** that boots directly into **Long Mode** and runs a single purpose: a retro **Ping Pong** game using CGA graphics. It's an educational and nostalgic project combining low-level OS development with a simple arcade-style game.

---

## 🎮 Features

- **Architecture**: x86_64 (64-bit Long Mode)
- **Display**:
  - CGA video mode
  - 320x200 resolution
  - 2-bit color palette (4 colors)
- **Game**: Pong-style game with:
  - Paddle control for both players
  - Ball movement and collision
  - Score display
  - Game Over screen
- **Input**:
  - **Left Shift**: Toggles the left paddle's vertical direction
  - **Right Shift**: Toggles the right paddle's vertical direction
- **No additional input**, sound, or storage—just pure Pong fun.

---

## 🧱 Technical Details

- **Binary Type**: Flat binary with a custom bootloader
- **Languages Used**: C and x86_64 Assembly
- **Paging**: Identity-mapped paging setup for entering long mode
- **Descriptors**:
  - GDT: Global Descriptor Table initialized
  - IDT: Interrupt Descriptor Table with essential exception ISRs
    - Includes Keyboard ISR (non-essential)
    - Includes PIT (Programmable Interval Timer) ISR (non-essential)
- **Game Engine**: Runs in kernel space as the only active process (no tasking or userspace)

---

## 🕹️ How to Play

- The game starts immediately after boot.
- **Left Player**: Press **Left Shift** to toggle the paddle's direction.
- **Right Player**: Press **Right Shift** to toggle the paddle's direction.
- The game continues until a player loses, after which the score is shown on a Game Over screen.

---

## 🚀 Getting Started

### Requirements

- An emulator such as:
  - [QEMU](https://www.qemu.org/)
  - [Bochs](http://bochs.sourceforge.net/)
  - Or real x86_64 hardware (CGA compatible)
- Optionally, a toolchain with:
  - `nasm`
  - `gcc`
  - `ld` or `ld.lld`

### Building
You can refer to the scripts provided inside the source folder of the repository for the process of building and check it out.

