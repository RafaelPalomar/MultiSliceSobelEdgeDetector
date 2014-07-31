#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkSobelEdgeDetectionImageFilter.h"

#include <iostream>

typedef itk::Image<float, 3> ImageType;
typedef itk::ImageFileReader<ImageType> ReaderType;
typedef itk::ImageFileWriter<ImageType> WriterType;
typedef itk::SobelEdgeDetectionImageFilter<ImageType, ImageType> SobelType;

int main(int argc, char **argv)
{

  ImageType::Pointer image = ImageType::New();

  if(argc != 3)
    {
    std::cerr << "Wrong number of arguments" << std::endl;
    }

  ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName(argv[1]);
  reader->Update();

  SobelType::Pointer sobelFilter = SobelType::New();
  sobelFilter->SetInput(reader->GetOutput());

  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(argv[2]);
  writer->SetInput(sobelFilter->GetOutput());
  writer->Update();

  return 0;
}
