#include "itkImageTrim3DFunction.h"

//.................................................................................................
// by     Dr. HSSHENG
// Email: shs3701001@gmai.com
//.................................................................................................

//.................................................................................................
// TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A 3D ITK IMAGE (UNSIGNED CHAR)
//.................................................................................................
// image: ITK 3D Image
// flag:  If all blank Image (>0) return false or return true
//.................................................................................................
void itk::ImageTrim3DFunction(
        itk::Image<unsigned char,3>::Pointer &image,
        bool flag)
{
    // typedef
    using ImageType = itk::Image<unsigned char,3>;
    using IteratorType = itk::ImageRegionIterator<ImageType>;

    // image size and initial trim size
    ImageType::PointType origin = image->GetOrigin();
    ImageType::SpacingType spacing = image->GetSpacing();
    ImageType::SizeType size = image->GetLargestPossibleRegion().GetSize();
    ImageType::IndexType start = image->GetLargestPossibleRegion().GetIndex();
    int trimSize[6];
    trimSize[0] = size[0]+start[0];
    trimSize[1] = start[0];
    trimSize[2] = size[1]+start[1];
    trimSize[3] = start[1];
    trimSize[4] = size[2]+start[2];
    trimSize[5] = start[2];

    // iterator of the whole image
    IteratorType iterator(image, image->GetLargestPossibleRegion());
    iterator.GoToBegin();
    while(!iterator.IsAtEnd())
    {
        unsigned char value = iterator.Get();
        ImageType::IndexType index = iterator.GetIndex();
        if(value>0)
        {
            trimSize[0] = index[0]<trimSize[0]?index[0]:trimSize[0];
            trimSize[1] = index[0]>trimSize[1]?index[0]:trimSize[1];
            trimSize[2] = index[1]<trimSize[2]?index[1]:trimSize[2];
            trimSize[3] = index[1]>trimSize[3]?index[1]:trimSize[3];
            trimSize[4] = index[2]<trimSize[4]?index[2]:trimSize[4];
            trimSize[5] = index[2]>trimSize[5]?index[2]:trimSize[5];
        }

        ++iterator;
    }
    if(trimSize[0]>trimSize[1] || trimSize[2]>trimSize[3] || trimSize[4]>trimSize[5])
    {
        flag = false;
        return;
    }
    flag = true;

    // trim Image
    ImageType::PointType orignTrim;
    orignTrim[0] = origin[0] + (trimSize[0]-1)*spacing[0];
    orignTrim[1] = origin[1] + (trimSize[2]-1)*spacing[1];
    orignTrim[2] = origin[2] + (trimSize[4]-1)*spacing[2];
    ImageType::IndexType startTrim;
    startTrim.Fill(0);
    ImageType::SizeType sizeTrim;
    sizeTrim[0] = trimSize[1] - trimSize[0] + 3;
    sizeTrim[1] = trimSize[3] - trimSize[2] + 3;
    sizeTrim[2] = trimSize[5] - trimSize[4] + 3;

    // resample
    using ResampleType = itk::ResampleImageFilter<ImageType,ImageType>;
    ResampleType::Pointer resample = ResampleType::New();
    resample->SetInput(image);
    resample->SetOutputOrigin(orignTrim);
    resample->SetOutputStartIndex(startTrim);
    resample->SetOutputSpacing(spacing);
    resample->SetSize(sizeTrim);
    try
    {
        resample->Update();
    }
    catch( itk::ExceptionObject & error )
    {
        std::cout<< "Error Update in itkImageTrim2DFunction"<<std::endl;
        std::cout << "Error: " << error << std::endl;
        return;
    }

    // get trimed image
    image = resample->GetOutput();
}

//.................................................................................................
// TRIM THE WHITE (DEFAULT VALUE 0) BOUNDARY OF A 3D ITK IMAGE (SIGNED SHORT)
//.................................................................................................
// image: ITK 3D Image
// flag:  If all blank Image (>-1000) return false or return true
//.................................................................................................
void itk::ImageTrim3DFunction(
        itk::Image<short,3>::Pointer &image,
        bool flag)
{
    // typedef
    using ImageType = itk::Image<short,3>;
    using IteratorType = itk::ImageRegionIterator<ImageType>;

    // image size and initial trim size
    ImageType::PointType origin = image->GetOrigin();
    ImageType::SpacingType spacing = image->GetSpacing();
    ImageType::SizeType size = image->GetLargestPossibleRegion().GetSize();
    ImageType::IndexType start = image->GetLargestPossibleRegion().GetIndex();
    int trimSize[6];
    trimSize[0] = size[0]+start[0];
    trimSize[1] = start[0];
    trimSize[2] = size[1]+start[1];
    trimSize[3] = start[1];
    trimSize[4] = size[2]+start[2];
    trimSize[5] = start[2];

    // iterator of the whole image
    IteratorType iterator(image, image->GetLargestPossibleRegion());
    iterator.GoToBegin();
    while(!iterator.IsAtEnd())
    {
        short value = iterator.Get();
        ImageType::IndexType index = iterator.GetIndex();
        if(value>0)
        {
            trimSize[0] = index[0]<trimSize[0]?index[0]:trimSize[0];
            trimSize[1] = index[0]>trimSize[1]?index[0]:trimSize[1];
            trimSize[2] = index[1]<trimSize[2]?index[1]:trimSize[2];
            trimSize[3] = index[1]>trimSize[3]?index[1]:trimSize[3];
            trimSize[4] = index[2]<trimSize[4]?index[2]:trimSize[4];
            trimSize[5] = index[2]>trimSize[5]?index[2]:trimSize[5];
        }

        ++iterator;
    }
    if(trimSize[0]>trimSize[1] || trimSize[2]>trimSize[3] || trimSize[4]>trimSize[5])
    {
        flag = false;
        return;
    }
    flag = true;

    // trim Image
    ImageType::PointType orignTrim;
    orignTrim[0] = origin[0] + (trimSize[0]-1)*spacing[0];
    orignTrim[1] = origin[1] + (trimSize[2]-1)*spacing[1];
    orignTrim[2] = origin[2] + (trimSize[4]-1)*spacing[2];
    ImageType::IndexType startTrim;
    startTrim.Fill(0);
    ImageType::SizeType sizeTrim;
    sizeTrim[0] = trimSize[1] - trimSize[0] + 3;
    sizeTrim[1] = trimSize[3] - trimSize[2] + 3;
    sizeTrim[2] = trimSize[5] - trimSize[4] + 3;

    // resample
    using ResampleType = itk::ResampleImageFilter<ImageType,ImageType>;
    ResampleType::Pointer resample = ResampleType::New();
    resample->SetInput(image);
    resample->SetOutputOrigin(orignTrim);
    resample->SetOutputStartIndex(startTrim);
    resample->SetOutputSpacing(spacing);
    resample->SetSize(sizeTrim);
    try
    {
        resample->Update();
    }
    catch( itk::ExceptionObject & error )
    {
        std::cout<< "Error Update in itkImageTrim2DFunction"<<std::endl;
        std::cout << "Error: " << error << std::endl;
        return;
    }

    // get trimed image
    image = resample->GetOutput();
}
