#include "itkImageTrim2DFunction.h"
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkPNGImageIOFactory.h>

int main()
{
    // typedef
    typedef itk::Image<unsigned char,2> ImageType;

    // tese image path
    std::string path = "../0.png";
    // reader
    itk::PNGImageIOFactory::RegisterOneFactory();
    typedef itk::ImageFileReader<ImageType> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(path);
    reader->Update();
    ImageType::Pointer image = reader->GetOutput();

    // trim
    bool trimedOrNot = true;
    itk::ImageTrim2DFunction(image, trimedOrNot);

}
