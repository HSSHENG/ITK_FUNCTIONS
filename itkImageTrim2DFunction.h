#ifndef ITKIMAGETRIM2DFUNCTION_H
#define ITKIMAGETRIM2DFUNCTION_H

#include <itkImage.h>
#include <itkImageRegionIterator.h>
#include <itkResampleImageFilter.h>

namespace itk
{
    //.................................................................................................
    // TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A UNSIGNED CHAR 2D ITK IMAGE
    //.................................................................................................
    // image: ITK 2D Image
    // flag:  If all blank Image return false or return true
    //.................................................................................................
    // by     Dr. HSSHENG
    // Email: shs3701001@gmai.com
    //.................................................................................................
    void ImageTrim2DFunction(
            itk::Image<unsigned char,2>::Pointer &image,
            bool flag);
}

#endif // ITKIMAGETRIM2DFUNCTION_H
