cmake_minimum_required(VERSION 3.22)
project(MathTheorey)

set(CMAKE_CXX_STANDARD 14)

add_executable(MathTheorey main.cpp )
add_executable(Projection Geometry/Projection.cpp)
add_executable(Distance Geometry/Distance.cpp  )
add_executable(Basic Geometry/Basic.cpp )
add_executable(Intersection Geometry/Intersection.cpp)
add_executable(Relection Geometry/Relection.cpp)
add_executable(Counter_Clockwise Geometry/Counter_Clockwise.cpp)
add_executable(Cross_Point  Geometry/Cross_Point.cpp)
add_executable(Cross_Point_Circle_Line  Geometry/Cross_Point_Circle_Line.cpp)
add_executable(Cross_Point_Circles  Geometry/Cross_Point_Circles.cpp)
add_executable(Polygon_Point_Containment  Geometry/Polygon_Point_Containment.cpp)
add_executable(Convex_Hull  Geometry/Convex_Hull.cpp)
add_executable(Segment_Intersection Geometry/Segment_Intersections.cpp)
add_executable(Parallel_Orthogonal Geometry/Parallel_Orthogonal.cpp)
add_executable(GDSE Optimization/GradientDescent_SolveEquation.cpp)
add_executable(Line_Intersection Geometry/Line_Intersections.cpp)
add_executable(Vector Geometry/Vector.cpp Geometry/Polygon.cpp)
add_executable(Polygon Geometry/Polygon.cpp) #多边形
add_executable(Point_Line  Geometry/Point_Line.cpp) #点与直线
add_executable(algebra  LinearAlgebra/SolveDet.cpp ) #求矩阵行列式
add_executable(LagrangeInterpolation NumericalAnalysis/LagrangeInterpolation.cpp) #Lagrange插值法
add_executable(Newton_SolveEquation Optimization/Newton_SolveEquation.cpp) #牛顿法求方程的根
add_executable(Binary_SolveEquation Optimization/Binary_SolveEquation.cpp) #二分法求方程的根
add_executable(Golden_SolveEquation Optimization/Golden_SolveEquation.cpp) #黄金分割法求含根区间
add_executable(Quadratic_SolveEquation Optimization/Quadratic_SolveEquation.cpp) #抛物线法求含根区间
add_executable(GradientDescent_ExtremeValue Optimization/GradientDescent_ExtremeValue.cpp) #梯度法求极值
add_executable(GradientDescent_ExtremeValue_MultiVariable Optimization/GradientDescent_ExtremeValue_MultiVariable.cpp) #梯度法求多元函数极值
add_executable(Newton_ExtremeValue Optimization/Newton_ExtremeValue.cpp) #牛顿法求函数极值点
add_executable(SimulatedAnnealing Optimization/SimulatedAnnealing.cpp) #模拟退火求函数极值点
add_executable(Convolution SignalsAndSystems/Convolution.cpp) #卷积实现


