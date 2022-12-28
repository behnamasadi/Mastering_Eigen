# Chapter 7 Geometry Transformation

- [Euler Angles](#euler-angles)
- [Quaternions](#quaternions)
- [Orthogonal Vector Generation](#orthogonal-vector-generation)
- [Parametrized Lines And Hyperplanes](#parametrized-lines-and-hyperplanes)
- [Least Square Transformation Fitting](#least-square-transformation-fitting)


# Euler Angles

The Euler angles are three angles to describe the orientation of a rigid body with respect to a fixed coordinate system.



The rotations may about the axes `XYZ` of the original coordinate system, which is assumed to remain motionless (extrinsic), or rotations about the axes of the rotating coordinate system `XYZ` (intrinsic), solidary with the moving body, which changes its orientation with respect to the extrinsic frame after each elemental rotation.

There exist twelve possible sequences of rotation axes, which can be divided into two categories: 
1. **Proper Euler angles**, where one axis of rotation is repeated (x-z-x, x-y-x, y-x-y, y-z-y, z-y-z, z-x-z), 
2. **Tait-Bryan angles**, which rotate around all axes (x-z-y, x-y-z, y-x-z, y-z-x, z-y-x, z-x-y).



Sometimes, both kinds of sequences are called "Euler angles". In that case, the sequences of the first group are called **proper** or **classic Euler** angles.


There are six possibilities of choosing the rotation axes for Tait–Bryan angles. The six possible sequences are:

- x-y′-z″ (intrinsic rotations) or z-y-x (extrinsic rotations)
- y-z′-x″ (intrinsic rotations) or x-z-y (extrinsic rotations)
- z-x′-y″ (intrinsic rotations) or y-x-z (extrinsic rotations)
- x-z′-y″ (intrinsic rotations) or y-z-x (extrinsic rotations)
- z-y′-x″ (intrinsic rotations) or x-y-z (extrinsic rotations): the intrinsic rotations are known as: yaw, pitch and roll
- y-x′-z″ (intrinsic rotations) or z-x-y (extrinsic rotations)


## Roll, Pitch and Yaw

Euler angles are typically denoted as:
- <img src="https://latex.codecogs.com/svg.image?&space;\gamma&space;\text{&space;or&space;}&space;\phi,&space;" title="https://latex.codecogs.com/svg.image? \gamma \text{ or } \phi, " /> represents a rotation around the x axis.
- <img src="https://latex.codecogs.com/svg.image?\beta,&space;\text{&space;or&space;}&space;\theta" title="https://latex.codecogs.com/svg.image?\beta, \text{ or } \theta" /> represents a rotation around the y axis,
- <img src="https://latex.codecogs.com/svg.image?\alpha&space;\text{&space;or&space;}&space;\psi" title="https://latex.codecogs.com/svg.image?\alpha \text{ or } \psi" /> represents a rotation around the z axis,


<br/>
<br/>







There are several axes conventions in practice for choosing the mobile and fixed axes and these conventions determine the signs of the angles.


Tait–Bryan angles are often used to describe a vehicle's attitude with respect to a chosen reference frame. The positive x-axis in vehicles points always in the direction of movement. For positive y- and z-axis, we have to face two different conventions:

- East, North, Up (ENU), used in geography (z is up and x is in the direction of move, y is pointing left)
- North, East, Down (NED), used specially in aerospace (z is down and x is in the direction of move, y is pointing right)



In case of land vehicles like cars, tanks  ENU-system (East-North-Up) as external reference (World frame), the vehicle's (body's) positive y- or pitch axis always points to its left, and the positive z- or yaw axis always points up.

<img src="images/RPY_angles_of_cars.png" />


In case of air and sea vehicles like submarines, ships, airplanes etc., which use the NED-system (North-East-Down) as external reference (World frame), the vehicle's (body's) positive y- or pitch axis always points to its right, and its positive z- or yaw axis always points down. 


<img src="images/RPY_angles_of_airplanes.png" />




# Other orientation representations
Euler angles are one way to represent orientations. There are others, and it is possible to change to and from other conventions. 

The most used orientation representation are:
- rotation matrices, 
- the axis-angle 
- quaternions, 

## Rotation matrix

<img src="https://latex.codecogs.com/svg.image?R_z(\alpha)=\bigl(\begin{smallmatrix}cos(\alpha)&space;&&space;-sin(\alpha)&space;&0&space;&space;\\&space;sin(\alpha)&space;&&space;&space;cos(\alpha)&space;&0&space;\\&space;&space;&space;&space;&space;&space;0&space;&space;&space;&space;&space;&space;&space;&space;&&space;&space;&space;&space;0&space;&space;&space;&&space;&space;1\\&space;\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R_z(\b)=\bigl(\begin{smallmatrix}cos(\alpha) & -sin(\alpha) &0 \\ sin(\alpha) & cos(\alpha) &0 \\ 0 & 0 & 1\\ \end{smallmatrix}\bigr)" />

<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?R_y(\beta)=\bigl(\begin{smallmatrix}cos(\beta)&space;&&space;0&space;&&space;sin(\beta)&space;\\&space;0&space;&&space;&space;1&space;&0&space;\\&space;&space;&space;-sin(\beta)&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&space;&&space;&space;&space;&space;0&space;&space;&space;&&space;&space;cos(\beta)\\&space;\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R_y(\beta)=\bigl(\begin{smallmatrix}cos(\beta) & 0 & sin(\beta) \\ 0 & 1 &0 \\ -sin(\beta) & 0 & cos(\beta)\\ \end{smallmatrix}\bigr)" />

<br/>
<br/>





<img src="https://latex.codecogs.com/svg.image?R(\alpha,\beta,&space;\gamma)=\bigl(\begin{smallmatrix}cos(\alpha)cos(&space;\beta)&space;&space;&&&space;&space;cos(\alpha)sin(\beta)sin(\gamma)&space;-sin(\alpha)cos(\gamma)&space;&space;&&&space;cos(\alpha)sin(\beta)cos(\gamma)&space;&plus;&space;sin(\alpha)sin(\gamma)&space;\\sin(\alpha)cos(&space;\beta)&space;&&&space;sin(\alpha)sin(\beta)sin(\gamma)&space;&plus;&space;cos(\alpha)cos(\gamma)&space;&&&space;sin(\alpha)sin(\beta)&space;cos(\gamma)&space;-&space;cos(&space;\alpha)sin(\gamma)&space;\\-sin(\beta)&space;&&&space;\cos(\beta)sin(\gamma)&space;&&&space;\cos(\beta)cos(\gamma)\end{smallmatrix}\bigr)" title="https://latex.codecogs.com/svg.image?R(\alpha,\beta, \gamma)=\bigl(\begin{smallmatrix}cos(\alpha)cos( \beta) && cos(\alpha)sin(\beta)sin(\gamma) -sin(\alpha)cos(\gamma) && cos(\alpha)sin(\beta)cos(\gamma) + sin(\alpha)sin(\gamma) \\sin(\alpha)cos( \beta) && sin(\alpha)sin(\beta)sin(\gamma) + cos(\alpha)cos(\gamma) && sin(\alpha)sin(\beta) cos(\gamma) - cos( \alpha)sin(\gamma) \\-sin(\beta) && \cos(\beta)sin(\gamma) && \cos(\beta)cos(\gamma)\end{smallmatrix}\bigr)" />




<br/>
<br/>


<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;{\begin{aligned}R=R_{z}(\alpha&space;)\,R_{y}(\beta&space;)\,R_{x}(\gamma&space;)&={\overset&space;{\text{yaw}}{\begin{bmatrix}\cos&space;\alpha&space;&-\sin&space;\alpha&space;&0\\\sin&space;\alpha&space;&\cos&space;\alpha&space;&0\\0&0&1\\\end{bmatrix}}}{\overset&space;{\text{pitch}}{\begin{bmatrix}\cos&space;\beta&space;&0&\sin&space;\beta&space;\\0&1&0\\-\sin&space;\beta&space;&0&\cos&space;\beta&space;\\\end{bmatrix}}}{\overset&space;{\text{roll}}{\begin{bmatrix}1&0&0\\0&\cos&space;\gamma&space;&-\sin&space;\gamma&space;\\0&\sin&space;\gamma&space;&\cos&space;\gamma&space;\\\end{bmatrix}}}\\&={\begin{bmatrix}\cos&space;\alpha&space;\cos&space;\beta&space;&\cos&space;\alpha&space;\sin&space;\beta&space;\sin&space;\gamma&space;-\sin&space;\alpha&space;\cos&space;\gamma&space;&\cos&space;\alpha&space;\sin&space;\beta&space;\cos&space;\gamma&space;&plus;\sin&space;\alpha&space;\sin&space;\gamma&space;\\\sin&space;\alpha&space;\cos&space;\beta&space;&\sin&space;\alpha&space;\sin&space;\beta&space;\sin&space;\gamma&space;&plus;\cos&space;\alpha&space;\cos&space;\gamma&space;&\sin&space;\alpha&space;\sin&space;\beta&space;\cos&space;\gamma&space;-\cos&space;\alpha&space;\sin&space;\gamma&space;\\-\sin&space;\beta&space;&\cos&space;\beta&space;\sin&space;\gamma&space;&\cos&space;\beta&space;\cos&space;\gamma&space;\\\end{bmatrix}}\end{aligned}}}" title="https://latex.codecogs.com/svg.image?{\displaystyle {\begin{aligned}R=R_{z}(\alpha )\,R_{y}(\beta )\,R_{x}(\gamma )&={\overset {\text{yaw}}{\begin{bmatrix}\cos \alpha &-\sin \alpha &0\\\sin \alpha &\cos \alpha &0\\0&0&1\\\end{bmatrix}}}{\overset {\text{pitch}}{\begin{bmatrix}\cos \beta &0&\sin \beta \\0&1&0\\-\sin \beta &0&\cos \beta \\\end{bmatrix}}}{\overset {\text{roll}}{\begin{bmatrix}1&0&0\\0&\cos \gamma &-\sin \gamma \\0&\sin \gamma &\cos \gamma \\\end{bmatrix}}}\\&={\begin{bmatrix}\cos \alpha \cos \beta &\cos \alpha \sin \beta \sin \gamma -\sin \alpha \cos \gamma &\cos \alpha \sin \beta \cos \gamma +\sin \alpha \sin \gamma \\\sin \alpha \cos \beta &\sin \alpha \sin \beta \sin \gamma +\cos \alpha \cos \gamma &\sin \alpha \sin \beta \cos \gamma -\cos \alpha \sin \gamma \\-\sin \beta &\cos \beta \sin \gamma &\cos \beta \cos \gamma \\\end{bmatrix}}\end{aligned}}}" />




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


## Signs and ranges

- for <img src="https://latex.codecogs.com/svg.image?\alpha&space;\text{&space;or&space;}&space;\psi" title="https://latex.codecogs.com/svg.image?\alpha \text{ or } \psi" /> and <img src="https://latex.codecogs.com/svg.image?&space;\gamma&space;\text{&space;or&space;}&space;\phi,&space;" title="https://latex.codecogs.com/svg.image? \gamma \text{ or } \phi, " />, the range is defined modulo <img src="https://latex.codecogs.com/svg.image?2\pi" title="https://latex.codecogs.com/svg.image?2\pi" />radians. For instance, a valid range could be <img src="https://latex.codecogs.com/svg.image?[-\pi,&space;\pi]" title="https://latex.codecogs.com/svg.image?[-\pi, \pi]" />.
- for <img src="https://latex.codecogs.com/svg.image?\beta,&space;\text{&space;or&space;}&space;\theta" title="https://latex.codecogs.com/svg.image?\beta, \text{ or } \theta" />, the range covers <img src="https://latex.codecogs.com/svg.image?&space;\pi&space;" title="https://latex.codecogs.com/svg.image? \pi " /> radians (but can't be said to be modulo <img src="https://latex.codecogs.com/svg.image?&space;\pi&space;" title="https://latex.codecogs.com/svg.image? \pi " />). For example, it could be <img src="https://latex.codecogs.com/svg.image?[0,&space;\pi]" title="https://latex.codecogs.com/svg.image?[0, \pi]" /> or <img src="https://latex.codecogs.com/svg.image?[-\pi/2,&space;\pi/2]" title="https://latex.codecogs.com/svg.image?[-\pi/2, \pi/2]" />.



# Gimbal lock 
The angles <img src="https://latex.codecogs.com/svg.image?\alpha,&space;\beta,&space;\text{&space;and&space;}&space;\gamma" title="https://latex.codecogs.com/svg.image?\alpha, \beta, \text{ and } \gamma" /> are uniquely determined except for the singular case. If <img src="https://latex.codecogs.com/svg.image?cos(\beta)=0&space;\text{&space;or&space;}&space;\beta=\pm&space;\pi/2" title="https://latex.codecogs.com/svg.image?cos(\beta)=0 \text{ or } \beta=\pm \pi/2" />

1. <img src="https://latex.codecogs.com/svg.image?\beta=\pi/2" title="https://latex.codecogs.com/svg.image?\beta=\pi/2" />
<br/>
<br/>

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}0&space;&&space;sin(\gamma-\alpha)&space;&&space;cos(\gamma-\alpha)\\0&space;&&space;cos(\gamma-\alpha)&space;&&space;-sin(\gamma-\alpha)\\-1&space;&&space;0&space;&&space;0\end{pmatrix}&space;=&space;\begin{pmatrix}0&space;&&space;r_{12}&space;&&space;r_{13}\\0&space;&&space;r_{22}&space;&&space;r_{23}\\-1&space;&&space;0&space;&&space;0\end{pmatrix}" title="https://latex.codecogs.com/svg.image?\begin{pmatrix}0 & sin(\gamma-\alpha) & cos(\gamma-\alpha)\\0 & cos(\gamma-\alpha) & -sin(\gamma-\alpha)\\-1 & 0 & 0\end{pmatrix} = \begin{pmatrix}0 & r_{12} & r_{13}\\0 & r_{22} & r_{23}\\-1 & 0 & 0\end{pmatrix}" />

This will result in:

- <img src="https://latex.codecogs.com/svg.image?\gamma-\alpha&space;=&space;atan2(r_{12},r_{22})" title="https://latex.codecogs.com/svg.image?\gamma-\alpha = atan2(r_{12},r_{22})" />

- <img src="https://latex.codecogs.com/svg.image?\gamma-\alpha&space;=&space;atan2(-r_{23},r_{13})&space;" title="https://latex.codecogs.com/svg.image?\gamma-\alpha = atan2(-r_{23},r_{13}) " />







<video width="640" height="480" controls>
  <source src="vidoes/gimbal_locl_beta_pi_2.mp4" type="video/mp4">
</video>
















2. <img src="https://latex.codecogs.com/svg.image?\beta=-\pi/2" title="https://latex.codecogs.com/svg.image?\beta=-\pi/2" />

<img src="https://latex.codecogs.com/svg.image?\begin{pmatrix}0&space;&&space;-sin(\gamma&plus;\alpha)&space;&&space;-cos(\gamma&plus;\alpha)\\0&space;&&space;cos(\gamma&plus;\alpha)&space;&&space;-sin(\gamma&plus;\alpha)\\1&space;&&space;0&space;&&space;0\end{pmatrix}&space;=&space;\begin{pmatrix}0&space;&&space;r_{12}&space;&&space;r_{13}\\0&space;&&space;r_{22}&space;&&space;r_{23}\\1&space;&&space;0&space;&&space;0\end{pmatrix}" title="https://latex.codecogs.com/svg.image?\begin{pmatrix}0 & -sin(\gamma+\alpha) & -cos(\gamma+\alpha)\\0 & cos(\gamma+\alpha) & -sin(\gamma+\alpha)\\1 & 0 & 0\end{pmatrix} = \begin{pmatrix}0 & r_{12} & r_{13}\\0 & r_{22} & r_{23}\\1 & 0 & 0\end{pmatrix}" />


This will result in:

- <img src="https://latex.codecogs.com/svg.image?\alpha&space;&plus;\gamma&space;=&space;atan2(-r_{12},r_{22})" title="https://latex.codecogs.com/svg.image?\alpha +\gamma = atan2(-r_{12},r_{22})" />

- <img src="https://latex.codecogs.com/svg.image?\gamma&plus;\alpha&space;=&space;atan2(-r_{23},-r_{13})" title="https://latex.codecogs.com/svg.image?\gamma+\alpha = atan2(-r_{23},-r_{13})" />

This means that there are infinitely many sets of (roll,yaw) angles for a given rotation matrix at with <img src="https://latex.codecogs.com/svg.image?\beta=\pm&space;\pi/2" title="https://latex.codecogs.com/svg.image?\beta=\pm \pi/2" />


Visit the [link](https://compsci290-s2016.github.io/CoursePage/Materials/EulerAnglesViz/) for interactive Gimbal visualization.





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

### Conversion between quaternions and Euler angles


 A unit quaternion can be described as:

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;\mathbf&space;{q}&space;={\begin{bmatrix}q_{0}&q_{1}&q_{2}&q_{3}\end{bmatrix}}^{T}={\begin{bmatrix}q_{w}&q_{x}&q_{y}&q_{z}\end{bmatrix}}^{T}}" title="https://latex.codecogs.com/svg.image?{\displaystyle \mathbf {q} ={\begin{bmatrix}q_{0}&q_{1}&q_{2}&q_{3}\end{bmatrix}}^{T}={\begin{bmatrix}q_{w}&q_{x}&q_{y}&q_{z}\end{bmatrix}}^{T}}" />

where 

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;|\mathbf&space;{q}&space;|^{2}=q_{0}^{2}&plus;q_{1}^{2}&plus;q_{2}^{2}&plus;q_{3}^{2}=q_{w}^{2}&plus;q_{x}^{2}&plus;q_{y}^{2}&plus;q_{z}^{2}=1}" title="https://latex.codecogs.com/svg.image?{\displaystyle |\mathbf {q} |^{2}=q_{0}^{2}+q_{1}^{2}+q_{2}^{2}+q_{3}^{2}=q_{w}^{2}+q_{x}^{2}+q_{y}^{2}+q_{z}^{2}=1}" />


To get the rotation matrix:


<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;R={\begin{bmatrix}1-2(q_{2}^{2}&plus;q_{3}^{2})&2(q_{1}q_{2}-q_{0}q_{3})&2(q_{0}q_{2}&plus;q_{1}q_{3})\\2(q_{1}q_{2}&plus;q_{0}q_{3})&1-2(q_{1}^{2}&plus;q_{3}^{2})&2(q_{2}q_{3}-q_{0}q_{1})\\2(q_{1}q_{3}-q_{0}q_{2})&2(q_{0}q_{1}&plus;q_{2}q_{3})&1-2(q_{1}^{2}&plus;q_{2}^{2})\end{bmatrix}}}" title="https://latex.codecogs.com/svg.image?{\displaystyle R={\begin{bmatrix}1-2(q_{2}^{2}+q_{3}^{2})&2(q_{1}q_{2}-q_{0}q_{3})&2(q_{0}q_{2}+q_{1}q_{3})\\2(q_{1}q_{2}+q_{0}q_{3})&1-2(q_{1}^{2}+q_{3}^{2})&2(q_{2}q_{3}-q_{0}q_{1})\\2(q_{1}q_{3}-q_{0}q_{2})&2(q_{0}q_{1}+q_{2}q_{3})&1-2(q_{1}^{2}+q_{2}^{2})\end{bmatrix}}}" />

To get the roll pitch, yaw:

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;{\begin{bmatrix}\phi&space;\\\theta&space;\\\psi&space;\end{bmatrix}}={\begin{bmatrix}{\mbox{atan2}}\left(2(q_{0}q_{1}&plus;q_{2}q_{3}),1-2(q_{1}^{2}&plus;q_{2}^{2})\right)\\-\pi&space;/2&plus;2\,{\mbox{atan2}}\left({\sqrt&space;{1&plus;2(q_{0}q_{2}-q_{1}q_{3})}},{\sqrt&space;{1-2(q_{0}q_{2}-q_{1}q_{3})}}\right)\\{\mbox{atan2}}\left(2(q_{0}q_{3}&plus;q_{1}q_{2}),1-2(q_{2}^{2}&plus;q_{3}^{2})\right)\end{bmatrix}}}" title="https://latex.codecogs.com/svg.image?{\displaystyle {\begin{bmatrix}\phi \\\theta \\\psi \end{bmatrix}}={\begin{bmatrix}{\mbox{atan2}}\left(2(q_{0}q_{1}+q_{2}q_{3}),1-2(q_{1}^{2}+q_{2}^{2})\right)\\-\pi /2+2\,{\mbox{atan2}}\left({\sqrt {1+2(q_{0}q_{2}-q_{1}q_{3})}},{\sqrt {1-2(q_{0}q_{2}-q_{1}q_{3})}}\right)\\{\mbox{atan2}}\left(2(q_{0}q_{3}+q_{1}q_{2}),1-2(q_{2}^{2}+q_{3}^{2})\right)\end{bmatrix}}}" />

### The advantages of Quaternions 

- Avoiding gimbal lock, a problem with systems such as Euler angles.
- Faster and more compact than matrices.
- Nonsingular representation (compared with Euler angles for example).



Refs: [1](https://www.youtube.com/watch?v=d4EgbgTm0Bg),[2](https://www.youtube.com/watch?v=zjMuIxRvygQ), [3](https://quaternions.online/), [4](https://www.youtube.com/watch?v=zc8b2Jo7mno), [5](https://www.youtube.com/watch?v=syQnn_xuB8U),
[6](https://www.youtube.com/watch?v=4mXL751ko0w)


# Axis-angle Representation

Axis-angle representation of a rotation in a three-dimensional Euclidean space by two quantities: 
1. A unit vector <img src="https://latex.codecogs.com/svg.image?\bold{e}" title="https://latex.codecogs.com/svg.image?\bold{e}" /> indicating the direction of an axis of rotation, 
2. An angle <img src="https://latex.codecogs.com/svg.image?\theta" title="https://latex.codecogs.com/svg.image?\theta" />

<img src="images/Angle_axis_vector.svg" />

<br/>
<br/>


<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;(\mathrm&space;{axis}&space;,\mathrm&space;{angle}&space;)=\left({\begin{bmatrix}e_{x}\\e_{y}\\e_{z}\end{bmatrix}},\theta&space;\right)=\left({\begin{bmatrix}0\\0\\1\end{bmatrix}},{\frac&space;{\pi&space;}{2}}\right).}" title="https://latex.codecogs.com/svg.image?{\displaystyle (\mathrm {axis} ,\mathrm {angle} )=\left({\begin{bmatrix}e_{x}\\e_{y}\\e_{z}\end{bmatrix}},\theta \right)=\left({\begin{bmatrix}0\\0\\1\end{bmatrix}},{\frac {\pi }{2}}\right).}" />

The above example can be represented as:

<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;{\begin{bmatrix}0\\0\\{\frac&space;{\pi&space;}{2}}\end{bmatrix}}.}" title="https://latex.codecogs.com/svg.image?{\displaystyle {\begin{bmatrix}0\\0\\{\frac {\pi }{2}}\end{bmatrix}}.}" />

## Rodrigues' Rotation Formula

If <img src="https://latex.codecogs.com/svg.image?\mathbf{v}" title="https://latex.codecogs.com/svg.image?\mathbf{v}" /> is a vector in <img src="https://latex.codecogs.com/svg.image?\mathbb{R}^3" title="https://latex.codecogs.com/svg.image?\mathbb{R}^3" /> and <img src="https://latex.codecogs.com/svg.image?\mathbf{k}" title="https://latex.codecogs.com/svg.image?\mathbf{k}" /> is a unit vector describing an axis of rotation by an angle <img src="https://latex.codecogs.com/svg.image?\theta" title="https://latex.codecogs.com/svg.image?\theta" />






<img src="https://latex.codecogs.com/svg.image?{\displaystyle&space;\mathbf&space;{v}&space;_{\mathrm&space;{rot}&space;}=\mathbf&space;{v}&space;\cos&space;\theta&space;&plus;(\mathbf&space;{k}&space;\times&space;\mathbf&space;{v}&space;)\sin&space;\theta&space;&plus;\mathbf&space;{k}&space;~(\mathbf&space;{k}&space;\cdot&space;\mathbf&space;{v}&space;)(1-\cos&space;\theta&space;)\,.}" title="https://latex.codecogs.com/svg.image?{\displaystyle \mathbf {v} _{\mathrm {rot} }=\mathbf {v} \cos \theta +(\mathbf {k} \times \mathbf {v} )\sin \theta +\mathbf {k} ~(\mathbf {k} \cdot \mathbf {v} )(1-\cos \theta )\,.}" />



## Exponential Coordinates

# Orthogonal Vector Generation

# Parametrized Lines And Hyperplanes

# Least Square Transformation Fitting 


[<< Previous ](6_Sparse_Matrices.md)  [Home](README.md)   [Next >>](8_Differentiation.md)
