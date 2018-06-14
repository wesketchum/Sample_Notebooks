void ShowUnderOverFlow(TH1* h1){
  h1->SetBinContent(1, h1->GetBinContent(0)+h1->GetBinContent(1));
  h1->SetBinContent(0,0);

  int nbins = h1->GetNbinsX();
  h1->SetBinContent(nbins, h1->GetBinContent(nbins)+h1->GetBinContent(nbins+1));
  h1->SetBinContent(nbins+1,0);

  h1->SetMinimum(0.0);
}

std::vector<std::string> GetFileNameList(std::string input_list,std::string prepend_path="")
{
    std::vector<std::string> filenames;

    std::ifstream input_file(input_list.c_str());
    std::string file_name;
    while(getline(input_file,file_name)){
        if(file_name.size()==0) continue;
        filenames.push_back(prepend_path+file_name);
    }
    return filenames;
}
