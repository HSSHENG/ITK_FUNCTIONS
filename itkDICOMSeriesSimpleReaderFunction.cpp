#include "itkDICOMSeriesSimpleReaderFunction.h"

//.................................................................................................
// A FUNCTION FOR READING DICOM SERIES
//.................................................................................................
void itk::DICOMSeriesSimpleReaderFunction(
        std::string dicomFilesPath,
        itk::Image<short,3>::Pointer &image3d)
{
    //typedef
    typedef itk::Image<short, 3> ImageType3dS;

    // initializing
    image3d = ImageType3dS::New();

    //.............................................................................................
    // read dicom files
    //.............................................................................................
    std::cout<<"Beigin read dicom..........................."<<std::endl;
    // typedef
    typedef itk::ImageSeriesReader<ImageType3dS> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    typedef itk::GDCMImageIO ImageIOType;
    ImageIOType::Pointer dicomIO = ImageIOType::New();
    reader->SetImageIO(dicomIO);

    typedef itk::GDCMSeriesFileNames NameGeneratorType;
    NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();

    nameGenerator->SetUseSeriesDetails(true);
    //nameGenerator->AddSeriesRestriction(dicomChar);
    nameGenerator->SetDirectory(dicomFilesPath);

    typedef std::vector<std::string> seriesIdContainer;
    const seriesIdContainer & seriesUID = nameGenerator->GetSeriesUIDs();

    seriesIdContainer::const_iterator seriesItr = seriesUID.begin();
    seriesIdContainer::const_iterator seriesEnd = seriesUID.end();
    while(seriesItr!=seriesEnd)
    {
        std::cout<<seriesItr->c_str()<<std::endl;
        ++seriesItr;
    }

    typedef std::vector<std::string> FilesNamesContainer;
    FilesNamesContainer filesNames;
    filesNames = nameGenerator->GetFileNames(seriesUID.begin()->c_str());

    reader->SetFileNames(filesNames);

    try
    {
        reader->Update();
    }
    catch(itk::ExceptionObject &ex)
    {
        std::cout<<ex<<std::endl;
        return;
    }

    image3d = reader->GetOutput();
    std::cout<<"End read dicom..........................."<<std::endl;
    return;
}

//.................................................................................................
// A FUNCTION FOR READING DICOM SERIES
//.................................................................................................
void itk::DICOMSeriesSimpleReaderFunction(
        std::string dicomFilesPath,
        itk::Image<float,3>::Pointer &image3d)
{
    //typedef
    typedef itk::Image<float, 3> ImageType3dF;

    // initializing
    image3d = ImageType3dF::New();

    //.............................................................................................
    // read dicom files
    //.............................................................................................
    std::cout<<"Beigin read dicom..........................."<<std::endl;
    // typedef
    typedef itk::ImageSeriesReader<ImageType3dF> ReaderType;
    ReaderType::Pointer reader = ReaderType::New();
    typedef itk::GDCMImageIO ImageIOType;
    ImageIOType::Pointer dicomIO = ImageIOType::New();
    reader->SetImageIO(dicomIO);

    typedef itk::GDCMSeriesFileNames NameGeneratorType;
    NameGeneratorType::Pointer nameGenerator = NameGeneratorType::New();

    nameGenerator->SetUseSeriesDetails(true);
    //nameGenerator->AddSeriesRestriction(dicomChar);
    nameGenerator->SetDirectory(dicomFilesPath);

    typedef std::vector<std::string> seriesIdContainer;
    const seriesIdContainer & seriesUID = nameGenerator->GetSeriesUIDs();

    seriesIdContainer::const_iterator seriesItr = seriesUID.begin();
    seriesIdContainer::const_iterator seriesEnd = seriesUID.end();
    while(seriesItr!=seriesEnd)
    {
        std::cout<<seriesItr->c_str()<<std::endl;
        ++seriesItr;
    }

    typedef std::vector<std::string> FilesNamesContainer;
    FilesNamesContainer filesNames;
    filesNames = nameGenerator->GetFileNames(seriesUID.begin()->c_str());

    reader->SetFileNames(filesNames);

    try
    {
        reader->Update();
    }
    catch(itk::ExceptionObject &ex)
    {
        std::cout<<ex<<std::endl;
        return;
    }

    image3d = reader->GetOutput();
    std::cout<<"End read dicom..........................."<<std::endl;
    return;
}
