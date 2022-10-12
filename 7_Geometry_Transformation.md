# Chapter 7 Geometry Transformation

- [Homogeneous Transformations](#homogeneous-transformations)
- [Translation, Scaling, and Rotations Matrices](#translation--scaling--and-rotations-matrices)
- [Euler Angles](#euler-angles)
- [Quaternions](#quaternions)
- [Orthogonal Vector Generation](#orthogonal-vector-generation)
- [Parametrized Lines And Hyperplanes](#parametrized-lines-and-hyperplanes)
- [Least Square Transformation Fitting](#least-square-transformation-fitting)



# Homogeneous Transformations

# Translation, Scaling, and Rotations Matrices

## Roll, Pitch and Yaw



<img src="images/roll_pitch_yaw.png" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?R_z(\alpha)=\bigl(\begin{smallmatrix}cos(\alpha)&space;&&space;-sin(\alpha)&space;&0&space;&space;\\&space;sin(\alpha)&space;&&space;&space;cos(\alpha)&space;&0&space;\\&space;&space;&space;&space;&space;&space;0&space;&space;&space;&space;&space;&space;&space;&space;&&space;&space;&space;&space;0&space;&space;&space;&&space;&space;1\\&space;\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R_z(\b)=\bigl(\begin{smallmatrix}cos(\alpha) & -sin(\alpha) &0 \\ sin(\alpha) & cos(\alpha) &0 \\ 0 & 0 & 1\\ \end{smallmatrix}\bigr)" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?R_y(\beta)=\bigl(\begin{smallmatrix}cos(\beta)&space;&&space;0&space;&&space;sin(\beta)&space;\\&space;0&space;&&space;&space;1&space;&0&space;\\&space;&space;&space;-sin(\beta)&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;&space;&space;&space;0&space;&space;&space;&&space;&space;cos(\beta)\\&space;\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R_y(\beta)=\bigl(\begin{smallmatrix}cos(\beta) & 0 & sin(\beta) \\ 0 & 1 &0 \\ -sin(\beta) & 0 & cos(\beta)\\ \end{smallmatrix}\bigr)" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?R_x(\gamma)=\bigl(\begin{smallmatrix}1&space;&&space;0&space;&&space;0&space;\\&space;0&space;&&space;&space;cos(\gamma)&space;&&space;-sin(\gamma)&space;\\&space;&space;&space;0&space;&space;&space;&space;&space;&&space;&space;&space;&space;sin(\gamma)&space;&space;&space;&&space;&space;cos(\gamma)\\&space;\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R_x(\gamma)=\bigl(\begin{smallmatrix}1 & 0 & 0 \\ 0 & cos(\gamma) & -sin(\gamma) \\ 0 & sin(\gamma) & cos(\gamma)\\ \end{smallmatrix}\bigr)" />

<br/>
<br/>



<img src="https://latex.codecogs.com/svg.image?R(\alpha,\beta,&space;\gamma)=\bigl(\begin{smallmatrix}cos(\alpha)cos(&space;\beta)&space;&space;&&&space;&space;cos(\alpha)sin(\beta)sin(\gamma)&space;-sin(\alpha)cos(\gamma)&space;&space;&&&space;cos(\alpha)sin(\beta)cos(\gamma)&space;&plus;&space;sin(\alpha)sin(\gamma)&space;\\sin(\alpha)cos(&space;\beta)&space;&&&space;sin(\alpha)sin(\beta)sin(\gamma)&space;&plus;&space;cos(\alpha)cos(\gamma)&space;&&&space;sin(\alpha)sin(\beta)&space;cos(\gamma)&space;-&space;cos(&space;\alpha)sin(\gamma)&space;\\-sin(\beta)&space;&&&space;\cos(\beta)sin(\gamma)&space;&&&space;\cos(\beta)cos(\gamma)\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R(\alpha,\beta, \gamma)=\bigl(\begin{smallmatrix}cos(\alpha)cos( \beta) && cos(\alpha)sin(\beta)sin(\gamma) -sin(\alpha)cos(\gamma) && cos(\alpha)sin(\beta)cos(\gamma) + sin(\alpha)sin(\gamma) \\sin(\alpha)cos( \beta) && sin(\alpha)sin(\beta)sin(\gamma) + cos(\alpha)cos(\gamma) && sin(\alpha)sin(\beta) cos(\gamma) - cos( \alpha)sin(\gamma) \\-sin(\beta) && \cos(\beta)sin(\gamma) && \cos(\beta)cos(\gamma)\end{smallmatrix}\bigr)" />



Multiple transformation matrices exist, and they can be applied in various orders. 
The twelve rotation sequences can be divided into two categories: 
1. Proper Euler angles, where one axis of rotation is repeated (x-z-x, x-y-x, y-x-y, y-z-y, z-y-z, z-x-z), 
2. Tait-Bryan angles, which rotate around all axes (x-z-y, x-y-z, y-x-z, y-z-x, z-y-x, z-x-y).

<br/>
<br/>

It is important to note that <img src="https://latex.codecogs.com/svg.image?&space;R(\alpha,\beta,\gamma)" title="https://latex.codecogs.com/svg.image? R(\alpha,\beta,\gamma)" /> performs the roll first, then the pitch, and finally the yaw. 

<br/>
<br/>















## Determining yaw, pitch, and roll from a rotation matrix

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}r_{11}&space;&&space;r_{12}&space;&r_{13}&space;&space;\\r_{21}&space;&&space;r_{22}&space;&&space;r_{23}&space;\\r_{31}&space;&&space;r_{32}&space;&&space;r_{33}&space;\\\end{pmatrix}" title="https://latex.codecogs.com/svg.image?\begin{pmatrix}r_{11} & r_{12} &r_{13} \\r_{21} & r_{22} & r_{23} \\r_{31} & r_{32} & r_{33} \\\end{pmatrix}" />

<br/>
<br/>
<img src="https://latex.codecogs.com/svg.image?tan(\alpha)=&space;\frac{r_{21}}{r_{11}}" title="https://latex.codecogs.com/svg.image?tan(\alpha)= \frac{r_{21}}{r_{11}}" />
<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?tan(\gamma)=&space;\frac{r_{32}}{r_{33}}" title="https://latex.codecogs.com/svg.image?tan(\gamma)= \frac{r_{32}}{r_{33}}" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?-sin(\beta)=r_{31}" title="https://latex.codecogs.com/svg.image?-sin(\beta)=r_{31}" />

and

<img src="https://latex.codecogs.com/svg.image?cos(\beta)=\sqrt{&space;&space;r_{32}^2&plus;&space;r_{33}^2}" title="https://latex.codecogs.com/svg.image?cos(\beta)=\sqrt{ r_{32}^2+ r_{33}^2}" />
<br/>
<br/>
There is a choice of four quadrants for the inverse tangent functions. Each quadrant should be chosen by using
the signs of the numerator and denominator of the argument. The <b>numerator</b> sign selects whether the direction will be above or below the <b> x-axis </b>, and the <b>denominator </b> selects whether the direction will be to the left or right of the <b>y-axis </b>. the function <b>atan2</b>
can calculate this for us:

- <img src="https://latex.codecogs.com/svg.image?\alpha=atan2(r_{21},r_{11})" title="https://latex.codecogs.com/svg.image?\alpha=atan2(r_{21},r_{11})" />

- <img src="https://latex.codecogs.com/svg.image?\beta=atan2(-r_{31},&space;\sqrt{&space;r_{32}^2&plus;&space;r_{33}^2})" title="https://latex.codecogs.com/svg.image?\beta=atan2(-r_{31}, \sqrt{ r_{32}^2+ r_{33}^2})" />

- <img src="https://latex.codecogs.com/svg.image?\gamma=atan2(-r_{32},r_{33})" title="https://latex.codecogs.com/svg.image?\gamma=atan2(-r_{32},r_{33})" />

Note that this method assumes <img src="https://latex.codecogs.com/svg.image?r_{11}\neq&space;0" title="https://latex.codecogs.com/svg.image?r_{11}\neq 0" /> and <img src="https://latex.codecogs.com/svg.image?r_{33}\neq&space;0" title="https://latex.codecogs.com/svg.image?r_{33}\neq 0" />.


Now what if <img src="https://latex.codecogs.com/svg.image?cos(\beta)=0&space;\text{&space;or&space;}&space;\beta=\pm&space;\pi/2" title="https://latex.codecogs.com/svg.image?cos(\beta)=0 \text{ or } \beta=\pm \pi/2" />

1. <img src="https://latex.codecogs.com/svg.image?\beta=\pi/2" title="https://latex.codecogs.com/svg.image?\beta=\pi/2" />
<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}0&space;&&space;sin(\gamma-\alpha)&space;&&space;cos(\gamma-\alpha)\\0&space;&&space;cos(\gamma-\alpha)&space;&&space;-sin(\gamma-\alpha)\\-1&space;&&space;0&space;&&space;0\end{pmatrix}&space;=&space;\begin{pmatrix}0&space;&&space;r_{12}&space;&&space;r_{13}\\0&space;&&space;r_{22}&space;&&space;r_{23}\\-1&space;&&space;0&space;&&space;0\end{pmatrix}" title="https://latex.codecogs.com/svg.image?\begin{pmatrix}0 & sin(\gamma-\alpha) & cos(\gamma-\alpha)\\0 & cos(\gamma-\alpha) & -sin(\gamma-\alpha)\\-1 & 0 & 0\end{pmatrix} = \begin{pmatrix}0 & r_{12} & r_{13}\\0 & r_{22} & r_{23}\\-1 & 0 & 0\end{pmatrix}" />

This will result in:

- <img src="https://latex.codecogs.com/svg.image?\gamma-\alpha&space;=&space;atan2(r_{12},r_{22})" title="https://latex.codecogs.com/svg.image?\gamma-\alpha = atan2(r_{12},r_{22})" />

- <img src="https://latex.codecogs.com/svg.image?\gamma-\alpha&space;=&space;atan2(-r_{23},r_{13})&space;" title="https://latex.codecogs.com/svg.image?\gamma-\alpha = atan2(-r_{23},r_{13}) " />


2. <img src="https://latex.codecogs.com/svg.image?\beta=-\pi/2" title="https://latex.codecogs.com/svg.image?\beta=-\pi/2" />

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}0&space;&&space;-sin(\gamma&plus;\alpha)&space;&&space;-cos(\gamma&plus;\alpha)\\0&space;&&space;cos(\gamma&plus;\alpha)&space;&&space;-sin(\gamma&plus;\alpha)\\1&space;&&space;0&space;&&space;0\end{pmatrix}&space;=&space;\begin{pmatrix}0&space;&&space;r_{12}&space;&&space;r_{13}\\0&space;&&space;r_{22}&space;&&space;r_{23}\\1&space;&&space;0&space;&&space;0\end{pmatrix}" title="https://latex.codecogs.com/svg.image?\begin{pmatrix}0 & -sin(\gamma+\alpha) & -cos(\gamma+\alpha)\\0 & cos(\gamma+\alpha) & -sin(\gamma+\alpha)\\1 & 0 & 0\end{pmatrix} = \begin{pmatrix}0 & r_{12} & r_{13}\\0 & r_{22} & r_{23}\\1 & 0 & 0\end{pmatrix}" />


This will result in:

- <img src="https://latex.codecogs.com/svg.image?\alpha&space;&plus;\gamma&space;=&space;atan2(-r_{12},r_{22})" title="https://latex.codecogs.com/svg.image?\alpha +\gamma = atan2(-r_{12},r_{22})" />

- <img src="https://latex.codecogs.com/svg.image?\gamma&plus;\alpha&space;=&space;atan2(-r_{23},-r_{13})" title="https://latex.codecogs.com/svg.image?\gamma+\alpha = atan2(-r_{23},-r_{13})" />

This means that there are infinitely many sets of (roll,yaw) angles for a given rotation matrix at with <img src="https://latex.codecogs.com/svg.image?\beta=\pm&space;\pi/2" title="https://latex.codecogs.com/svg.image?\beta=\pm \pi/2" />


Visit the [link](https://compsci290-s2016.github.io/CoursePage/Materials/EulerAnglesViz/) for interactive Gimbal visualization.

## Euler Angles

## Quaternions

quaternion number system extends the complex numbers which introduced by William Rowan Hamilton. Hamilton defined a quaternion as the <b>quotient</b> of two vectors (two lines in a three-dimensional space). Quaternions are generally represented in the form:


<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;a&plus;b\&space;\mathbf&space;{i}&space;&plus;c\&space;\mathbf&space;{j}&space;&plus;d\&space;\mathbf&space;{k}&space;}" title="https://latex.codecogs.com/svg.image?{\displaystyle a+b\ \mathbf {i} +c\ \mathbf {j} +d\ \mathbf {k} }" />

where a, b, c, and d are real numbers; and i, j, and k are the basic quaternions ( symbols that can be interpreted as unit-vectors pointing along the three spatial axes).


a quaternion <img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;q=a&plus;b\,\mathbf&space;{i}&space;&plus;c\,\mathbf&space;{j}&space;&plus;d\,\mathbf&space;{k}&space;}" title="https://latex.codecogs.com/svg.image?{\displaystyle q=a+b\,\mathbf {i} +c\,\mathbf {j} +d\,\mathbf {k} }" />, as consisting of a scalar part and a vector part. 
The quaternion <img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;b\,\mathbf&space;{i}&space;&plus;c\,\mathbf&space;{j}&space;&plus;d\,\mathbf&space;{k}&space;}" title="https://latex.codecogs.com/svg.image?{\displaystyle b\,\mathbf {i} +c\,\mathbf {j} +d\,\mathbf {k} }" />  is called the vector part (sometimes imaginary part) of q, and <img src="https://latex.codecogs.com/svg.image?a" title="https://latex.codecogs.com/svg.image?a" /> is the scalar part (sometimes real part) of q.

### Basis
The set of quaternions is made a 4-dimensional vector space over the real numbers, with <img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;\left\{1,\mathbf&space;{i}&space;,\mathbf&space;{j}&space;,\mathbf&space;{k}&space;\right\}}" title="https://latex.codecogs.com/svg.image?{\displaystyle \left\{1,\mathbf {i} ,\mathbf {j} ,\mathbf {k} \right\}}" /> as a basis, by the componentwise addition


<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;{\begin{aligned}\mathbf&space;{j\,k}&space;&=\mathbf&space;{i}&space;\,,\quad&space;&\mathbf&space;{k\,j}&space;&=-\mathbf&space;{i}&space;\,,\\\mathbf&space;{k\,i}&space;&=\mathbf&space;{j}&space;\,,\quad&space;&\mathbf&space;{i\,k}&space;&=-\mathbf&space;{j}&space;\,,\\\mathbf&space;{i\,j\,k}&space;&=-1\,,\quad&space;&\mathbf&space;{k}&space;^{2}&=-1\,\\\end{aligned}}}" title="https://latex.codecogs.com/svg.image?{\displaystyle {\begin{aligned}\mathbf {j\,k} &=\mathbf {i} \,,\quad &\mathbf {k\,j} &=-\mathbf {i} \,,\\\mathbf {k\,i} &=\mathbf {j} \,,\quad &\mathbf {i\,k} &=-\mathbf {j} \,,\\\mathbf {i\,j\,k} &=-1\,,\quad &\mathbf {k} ^{2}&=-1\,\\\end{aligned}}}" />

<br/>
<br/>
<img src="images/Quaternion_2.svg" height=200 width=200 />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;\mathbf&space;{i}&space;^{2}=\mathbf&space;{j}&space;^{2}=\mathbf&space;{k}&space;^{2}=\mathbf&space;{i\,j\,k}&space;=-1}" title="https://latex.codecogs.com/svg.image?{\displaystyle \mathbf {i} ^{2}=\mathbf {j} ^{2}=\mathbf {k} ^{2}=\mathbf {i\,j\,k} =-1}" />



### Hamilton product

For two elements <img src="https://latex.codecogs.com/svg.image?a_1&space;&plus;&space;b_1i&space;&plus;c_1j&plus;d_1k" title="https://latex.codecogs.com/svg.image?a_1 + b_1i +c_1j+d_1k" /> and <img src="https://latex.codecogs.com/svg.image?a_2&space;&plus;&space;b_2i&space;&plus;c_2j&plus;d_2k" title="https://latex.codecogs.com/svg.image?a_2 + b_2i +c_2j+d_2k" />, their product, called the Hamilton product and is determined by distributive law:

<br/>
<br/>
<img src="https://latex.codecogs.com/svg.image?(a_1&space;&plus;&space;b_1i&space;&plus;c_1j&plus;d_1k)(a_2&space;&plus;&space;b_2i&space;&plus;c_2j&plus;d_2k)" title="https://latex.codecogs.com/svg.image?(a_1 + b_1i +c_1j+d_1k)(a_2 + b_2i +c_2j+d_2k)" />
<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?=&space;{\begin{alignedat}{}&a_{1}a_{2}&&&plus;a_{1}b_{2}\mathbf&space;{i}&space;&&&plus;a_{1}c_{2}\mathbf&space;{j}&space;&&&plus;a_{1}d_{2}\mathbf&space;{k}&space;\\{}&plus;{}&b_{1}a_{2}\mathbf&space;{i}&space;&&&plus;b_{1}b_{2}\mathbf&space;{i}&space;^{2}&&&plus;b_{1}c_{2}\mathbf&space;{ij}&space;&&&plus;b_{1}d_{2}\mathbf&space;{ik}&space;\\{}&plus;{}&c_{1}a_{2}\mathbf&space;{j}&space;&&&plus;c_{1}b_{2}\mathbf&space;{ji}&space;&&&plus;c_{1}c_{2}\mathbf&space;{j}&space;^{2}&&&plus;c_{1}d_{2}\mathbf&space;{jk}&space;\\{}&plus;{}&d_{1}a_{2}\mathbf&space;{k}&space;&&&plus;d_{1}b_{2}\mathbf&space;{ki}&space;&&&plus;d_{1}c_{2}\mathbf&space;{kj}&space;&&&plus;d_{1}d_{2}\mathbf&space;{k}&space;^{2}\end{alignedat}}" title="https://latex.codecogs.com/svg.image?= {\begin{alignedat}{}&a_{1}a_{2}&&+a_{1}b_{2}\mathbf {i} &&+a_{1}c_{2}\mathbf {j} &&+a_{1}d_{2}\mathbf {k} \\{}+{}&b_{1}a_{2}\mathbf {i} &&+b_{1}b_{2}\mathbf {i} ^{2}&&+b_{1}c_{2}\mathbf {ij} &&+b_{1}d_{2}\mathbf {ik} \\{}+{}&c_{1}a_{2}\mathbf {j} &&+c_{1}b_{2}\mathbf {ji} &&+c_{1}c_{2}\mathbf {j} ^{2}&&+c_{1}d_{2}\mathbf {jk} \\{}+{}&d_{1}a_{2}\mathbf {k} &&+d_{1}b_{2}\mathbf {ki} &&+d_{1}c_{2}\mathbf {kj} &&+d_{1}d_{2}\mathbf {k} ^{2}\end{alignedat}}" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?={\displaystyle&space;{\begin{alignedat}{}&a_{1}a_{2}&&-b_{1}b_{2}&&-c_{1}c_{2}&&-d_{1}d_{2}\\{}&plus;{}(&a_{1}b_{2}&&&plus;b_{1}a_{2}&&&plus;c_{1}d_{2}&&-d_{1}c_{2})\mathbf&space;{i}&space;\\{}&plus;{}(&a_{1}c_{2}&&-b_{1}d_{2}&&&plus;c_{1}a_{2}&&&plus;d_{1}b_{2})\mathbf&space;{j}&space;\\{}&plus;{}(&a_{1}d_{2}&&&plus;b_{1}c_{2}&&-c_{1}b_{2}&&&plus;d_{1}a_{2})\mathbf&space;{k}&space;\end{alignedat}}}" title="https://latex.codecogs.com/svg.image?={\displaystyle {\begin{alignedat}{}&a_{1}a_{2}&&-b_{1}b_{2}&&-c_{1}c_{2}&&-d_{1}d_{2}\\{}+{}(&a_{1}b_{2}&&+b_{1}a_{2}&&+c_{1}d_{2}&&-d_{1}c_{2})\mathbf {i} \\{}+{}(&a_{1}c_{2}&&-b_{1}d_{2}&&+c_{1}a_{2}&&+d_{1}b_{2})\mathbf {j} \\{}+{}(&a_{1}d_{2}&&+b_{1}c_{2}&&-c_{1}b_{2}&&+d_{1}a_{2})\mathbf {k} \end{alignedat}}}" />

### Inverse with respect to the Hamilton product

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;(a&plus;b\,\mathbf&space;{i}&space;&plus;c\,\mathbf&space;{j}&space;&plus;d\,\mathbf&space;{k}&space;)^{-1}={\frac&space;{1}{a^{2}&plus;b^{2}&plus;c^{2}&plus;d^{2}}}\,(a-b\,\mathbf&space;{i}&space;-c\,\mathbf&space;{j}&space;-d\,\mathbf&space;{k}&space;).}" title="https://latex.codecogs.com/svg.image?{\displaystyle (a+b\,\mathbf {i} +c\,\mathbf {j} +d\,\mathbf {k} )^{-1}={\frac {1}{a^{2}+b^{2}+c^{2}+d^{2}}}\,(a-b\,\mathbf {i} -c\,\mathbf {j} -d\,\mathbf {k} ).}" />


### Conjugation 
### Norm
### Reciprocal



### The advantages of Quaternions 

- Avoiding gimbal lock, a problem with systems such as Euler angles.
- Faster and more compact than matrices.
- Nonsingular representation (compared with Euler angles for example).



Refs: [1](https://www.youtube.com/watch?v=d4EgbgTm0Bg),[2](https://www.youtube.com/watch?v=zjMuIxRvygQ), [3](https://quaternions.online/), [4](https://www.youtube.com/watch?v=zc8b2Jo7mno), [5](https://www.youtube.com/watch?v=syQnn_xuB8U),
[6](https://www.youtube.com/watch?v=4mXL751ko0w)


## Exponential Coordinates

# Orthogonal Vector Generation

# Parametrized Lines And Hyperplanes

# Least Square Transformation Fitting 


[<< Previous ](6_Sparse_Matrices.md)  [Home](README.md)   [Next >>](8_Differentiation.md)
