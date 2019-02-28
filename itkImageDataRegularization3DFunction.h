#ifndef ITKIMAGEDATAREGULARIZATION3DFUNCTION_H
#define ITKIMAGEDATAREGULARIZATION3DFUNCTION_H

#include <itkImage.h>
#include <itkExtractImageFilter.h>
#include <itkResampleImageFilter.h>
#include <itkNearestNeighborInterpolateImageFunction.h>

namespace itk
{
    //.................................................................................................
    // REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION UNSIGNED CHAR FORMAT
    //.................................................................................................
    void ImageDataRegularization3DFunction(
            itk::Image<unsigned char,3>::Pointer &image);

    //.................................................................................................
    // REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION SHORT FORMAT
    //.................................................................................................
    void ImageDataRegularization3DFunction(
            itk::Image<short,3>::Pointer &image);

    //.................................................................................................
    // REGULARIZATION FOR THESE 3D IMAGE WITH NON-IDENTITY DIRECTION FLOAT FORMAT
    //.................................................................................................
    void ImageDataRegularization3DFunction(
            itk::Image<float,3>::Pointer &image);
}


#endif // ITKIMAGEDATAREGULARIZATION3DFUNCTION_H
