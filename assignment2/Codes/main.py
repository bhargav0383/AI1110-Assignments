import sympy as smp

x = smp.symbols("x")
C = x**3/3 + 3*x**2 - 16*x + 2
derivative_C = C.diff(x)
derivative_C