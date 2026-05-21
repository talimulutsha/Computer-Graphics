# Computer-Graphics

# Beach Scene OpenGL Project Controls

## Keyboard Controls

| Key       | Function                                 |
| --------- | ---------------------------------------- |
| `1`       | Switch to Scene 1 (Beach & Yacht Scene)  |
| `2`       | Switch to Scene 2 (Village & Boat Scene) |
| `N` / `n` | Enable Night Mode in Scene 1             |
| `M` / `m` | Enable Day Mode in Scene 1               |
| `V` / `v` | Enable Night Mode in Scene 2             |
| `B` / `b` | Enable Day Mode in Scene 2               |
| `S` / `s` | Start First Boat Movement in Scene 2     |
| `D` / `d` | Start Second Boat Movement in Scene 2    |

---

# Mouse Controls

| Mouse Button | Function                    |
| ------------ | --------------------------- |
| Right Click  | Increase Boat & Cloud Speed |
| Left Click   | Decrease Boat & Cloud Speed |

---

# Automatic Animations

The following animations run automatically using `glutTimerFunc()`:

* Moving clouds
* Moving yacht
* Moving sun/moon
* Windmill blade rotation
* Scene animation refresh

---

# Graphics Features Used

* OpenGL 2D Graphics
* Polygon Drawing
* Transformation (`glTranslatef`, `glRotatef`)
* Animation using Timer Function
* Day/Night Color Transition
* Keyboard Interaction
* Mouse Interaction
* Double Buffering (`GLUT_DOUBLE`)

---

# Coordinate System

```cpp
gluOrtho2D(-1,1,-1,1);
```

This creates a 2D coordinate system from:

* X-axis: `-1 to +1`
* Y-axis: `-1 to +1`

---

# Window Size

```cpp
glutInitWindowSize(1000, 700);
```

Window resolution:

* Width = 1000 pixels
* Height = 700 pixels
