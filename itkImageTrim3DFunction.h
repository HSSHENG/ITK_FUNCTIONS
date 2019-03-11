#ifndef ITKIMAGETRIM2DFUNCTION_H
#define ITKIMAGETRIM2DFUNCTION_H

#include <itkImage.h>
#include <itkImageRegionIterator.h>
#include <itkResampleImageFilter.h>

namespace itk
{
    //.................................................................................................
    // TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A 3D ITK IMAGE (UNSIGNED CHAR)
    //.................................................................................................
    // image: ITK 3D Image
    // flag:  If all blank Image (>0) return false or return true
    //.................................................................................................
    void ImageTrim3DFunction(
            itk::Image<unsigned char,3>::Pointer &image,
            bool flag);

    //.................................................................................................
    // TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A 3D ITK IMAGE (SIGNED SHORT)
    //.................................................................................................
    // image: ITK 3D Image
    // flag:  If all blank Image (>-1000) return false or return true
    //.................................................................................................
    void ImageTrim3DFunction(
            itk::Image<short,3>::Pointer &image,
            bool flag);

    //.................................................................................................
    // TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A 3D ITK IMAGE (FLOAT)
    //.................................................................................................
    // image: ITK 3D Image
    // flag:  If all blank Image (>-1000) return false or return true
    //.................................................................................................
    void ImageTrim3DFunction(
            itk::Image<float,3>::Pointer &image,
            bool flag);
}

#endif // ITKIMAGETRIM2DFUNCTION_H
