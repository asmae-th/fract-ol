# 🌌 Fract-ol

> A graphical fractal renderer built using the MiniLibX library — developed as part of the 42 coding school curriculum.

---

## 🎯 Project Overview

**Fract-ol** is a graphical application designed to explore and render fractals in real time using the MiniLibX graphical library.
The project focuses on rendering **Mandelbrot**, **Julia**, and potentially other fractals with interactive zooming and color effects.

This project is an opportunity to explore:

* Complex numbers
* Iterative algorithms
* Real-time graphical rendering
* Mouse and keyboard interaction handling

---

## 🌀 Supported Fractals

* 🌌 **Mandelbrot Set**
* 🔠 **Julia Set**
* ✨ Bonus: Other custom or rare fractals

---

## 💻 Technologies Used

* C Programming Language
* MiniLibX (graphics library)
* Complex number arithmetic
* Makefile & Norminette compliant

---

## 🛠️ Features

✅ Real-time fractal rendering
✅ Zoom in/out with mouse scroll
✅ Move fractal with arrow keys
✅ Change color schemes
✅ Switch between fractal types
✅ Bonus: Interactive Julia set via mouse movement

---

## 📁 Project Structure

```
fract-ol/
├── Makefile
├── fractol.c
├── mandelbrot.c
├── julia.c
├── utils.c
├── colors.c
├── mlx_hooks.c
├── includes/
│   └── fractol.h
```

---

## 🧠 Key Concepts

* **Complex Numbers:** Used to define and iterate over points in the complex plane.
* **Escape Time Algorithm:** Determines color based on how quickly a point escapes the fractal bounds.
* **Color Mapping:** Translates iterations into RGB gradients.

---

## 🖥️ How to Use

### 🧱 Compile the Project

```bash
make
```

### 🚀 Run the Program

```bash
./fractol mandelbrot
./fractol julia
```

You can also pass a custom complex number for Julia:

```bash
./fractol julia -0.8 0.156
```

---

## 🎮 Controls

| Action              | Key/Mouse              |
| ------------------- | ---------------------- |
| Zoom in/out         | Scroll Wheel           |
| Move View           | Arrow Keys             |
| Switch Color Set    | `C`                    |
| Reset View          | `R`                    |
| Exit Program        | `ESC`                  |
| Julia Interactivity | Mouse Movement (Bonus) |

---

## 🧪 Bonus Ideas

* 🔀 Cycle through fractals (`F` key)
* 👡 Interactive Julia with live feedback
* 📀 Save screenshot
* 🧮 Add Newton Fractal or Burning Ship

---

## 🧑‍💼 Author

-Made with curiosity and pixels by Asmae TAHTOUH
-This project was built as part of the 42 school curriculum.

---

## 🧼 Norminette & Makefile

* Fully compliant with 42 Norm
* Clean and modular codebase
* Single rule compilation

---

## 📸 Gallery (optional)

Include your own screenshots of:

* Mandelbrot full zoom
* Color palette examples
* Julia set morphing

---

## 📚 References

* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
* [Fractal Guide](https://en.wikipedia.org/wiki/Fractal)
* [Mandelbrot & Julia Sets](https://mathworld.wolfram.com/MandelbrotSet.html)

---
