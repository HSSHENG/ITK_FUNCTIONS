#ifndef ITKDICOMSERIESSIMPLEREADERFUNCTION_H
#define ITKDICOMSERIESSIMPLEREADERFUNCTION_H

#include <itkImage.h>
#include <itkGDCMImageIO.h>
#include <itkGDCMImageIOFactory.h>
#include <itkGDCMSeriesFileNames.h>
#include <itkImageSeriesReader.h>

namespace itk
{
    //.................................................................................................
    // A FUNCTION FOR READING DICOM SERIES
    //.................................................................................................
    void DICOMSeriesSimpleReaderFunction(
            std::string dicomFilesPath,
            itk::Image<short,3>::Pointer &image3d);

    //.................................................................................................
    // A FUNCTION FOR READING DICOM SERIES
    //.................................................................................................
    void DICOMSeriesSimpleReaderFunction(
            std::string dicomFilesPath,
            itk::Image<float,3>::Pointer &image3d);
}
#endif // ITKDICOMSERIESSIMPLEREADERFUNCTION_H
