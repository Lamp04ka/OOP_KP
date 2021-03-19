#include "bd.h"


BD::BD()
{

}

bool BD::wainGP(QList<std::string> G, std::string P, int day, int para){
    for(int i=0;i<lessons_data.size();i++)
    {
        int les_day=lessons_data[i].getDays_in_weekInt();
        int les_para=lessons_data[i].getNumberPara();
        std::string les_GP=lessons_data[i].getName_GP();
        for(int j=0;j<G.size();j++){
            if(les_GP==P&&les_para==para&&les_day==day||les_GP==G[j]&&les_para==para&&les_day==day)
                return true;
        }
    }
    return false;
}

bool BD::waitTeacher(int id_teacher,int day,int para){
    for(int i=0;i<lessons_data.size();i++)
        if(id_teacher==lessons_data[i].getIdTeacher()&&day==lessons_data[i].getDays_in_weekInt()&&para==lessons_data[i].getNumberPara())
            return true;
    return false;
}

bool BD::waitCabinet(int day, int para){
    int iter=0;
    for(int j=0;j<cabs_data.size();j++)
        for(int i=0;i<lessons_data.size();i++)
            if(cabs_data[j].getCab()==lessons_data[i].getCab()&&cabs_data[j].getAddressInt()==lessons_data[i].getAddressInt()&&day==lessons_data[i].getDays_in_weekInt()&&para==lessons_data[i].getNumberPara())
                iter++;
    if(iter==cabs_data.size())
        return true;
    else
        return false;
}



void BD::readPredmet()
{
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffA,buffB;
    int iter=1;
    QString a_iter="A2",b_iter;
    buffA = xlsx.read(a_iter);
    if(buffA.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffA.toBool())
        {
            iter++;
            a_iter="A";
            b_iter="B";
            a_iter.push_back(QString::number(iter));
            b_iter.push_back(QString::number(iter));
            buffA = xlsx.read(a_iter);
            buffB = xlsx.read(b_iter);
            if(!buffA.toBool())
                continue;
            Predmet *Body = new Predmet(buffA.toInt(),buffB.toString().toStdString());
            this->predmet_data.push_back(*Body);
        }
    }
    return;
}
void BD::writePredmet(){
     QXlsx::Document xlsx("BD.xlsx");
     int iter=1;
     for(int i=0;i<this->predmet_data.size();i++)
     {
         iter++;
         QString a_iter="A";
         QString b_iter="B";
         a_iter.push_back(QString::number(iter));
         b_iter.push_back(QString::number(iter));
         xlsx.write(a_iter,this->predmet_data[i].getIdPredmet());
         xlsx.write(b_iter,QString::fromUtf8(this->predmet_data[i].getNamePredmet().data(),this->predmet_data[i].getNamePredmet().size()));
     }
     for(int i=this->predmet_data.size();i<1500;i++)
     {
         iter++;
         QString a_iter="A";
         QString b_iter="B";
         a_iter.push_back(QString::number(iter));
         b_iter.push_back(QString::number(iter));
         xlsx.write(a_iter,"");
         xlsx.write(b_iter,"");
     }
     xlsx.saveAs("BD.xlsx");
}
void BD::sortPredmet(){   std::sort(predmet_data.begin(), predmet_data.end());}
bool BD::addPredmet(QString i_name){
    bool flag=true;
    int buf=predmet_data.size()+1;
    for(int i=0;i<predmet_data.size();i++)
        if(predmet_data[i].getNamePredmet()==i_name.toStdString())
            flag=false;
    if(flag==false)
        return false;
    for(int i=0;i<predmet_data.size();i++)
        if(i+1!=predmet_data[i].getIdPredmet()){
            buf=i+1;
            break;
        }
    Predmet body(buf, i_name.toStdString());
    predmet_data.append(body);
    this->sortPredmet();
    return true;
}
bool BD::deletePredmet(int i_id)
{
    for(int i=0;i<predmet_data.size();i++)
        if(predmet_data[i].getIdPredmet()==i_id){
            predmet_data.removeAt(i);
            return true;
        }
    return false;
}
QList<Predmet> BD::getPredmet(){    return this->predmet_data;}
Predmet BD::returnPredmet(int i_id){return predmet_data[i_id];}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BD::readPlan(){
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffC,buffD,buffE,buffF,buffG,buffZ;
    int iter=1;
    QString c_iter="C2",d_iter,e_iter,f_iter,g_iter,z_iter;
    buffC = xlsx.read(c_iter);
    if(buffC.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffC.toBool())
        {
            iter++;
            c_iter="C";//к.нагрузки
            d_iter="D";//часы
            e_iter="E";//к.дисциплины
            f_iter="F";//тип нагрузки
            g_iter="G";//№ группы или поток
            z_iter="Z";
            c_iter.push_back(QString::number(iter));
            d_iter.push_back(QString::number(iter));
            e_iter.push_back(QString::number(iter));
            f_iter.push_back(QString::number(iter));
            g_iter.push_back(QString::number(iter));
            z_iter.push_back(QString::number(iter));
            buffC = xlsx.read(c_iter);
            if(!buffC.toBool())
                continue;
            Predmet body_p;
            Teacher body_t;
            bool flag=false;
            buffE = xlsx.read(e_iter);
            for(int i=0;i<predmet_data.size();i++)
                if(predmet_data[i].getIdPredmet()==buffE)
                {
                    body_p=predmet_data[i];
                    flag=true;
                }
            if(flag==false)
                continue;
            flag=false;
            buffZ = xlsx.read(z_iter);
            for(int i=0;i<teachers_data.size();i++)
                if(teachers_data[i].getIdTeacher()==buffZ.toInt()){
                    body_t=teachers_data[i];
                    flag=true;
            }
            if(flag==false)
                continue;
            buffD = xlsx.read(d_iter);
            buffF = xlsx.read(f_iter);
            buffG = xlsx.read(g_iter);
            for(int i=0;i<grupps_data.size();i++)
                if(grupps_data[i].getNameGrupp()==buffG.toString().toStdString()||grupps_data[i].getNumPotoka()==buffG.toString().toStdString())
                    flag=false;
            if(flag==true)
                continue;
            Uchebni_plan *BodyPlan = new  Uchebni_plan(buffC.toInt(), buffD.toInt(),buffF.toInt(),buffG.toString().toStdString(),body_p,body_t);
            this->plan_data.push_back(*BodyPlan);
        }
        return;
    }
}
void BD::writePlan(){
     QXlsx::Document xlsx("BD.xlsx");
     int iter=1;
     for(int i=0;i<this->plan_data.size();i++)
     {
         iter++;
         QString c_iter="C";
         QString d_iter="D";
         QString e_iter="E";
         QString f_iter="F";
         QString g_iter="G";
         QString z_iter="Z";
         c_iter.push_back(QString::number(iter));
         d_iter.push_back(QString::number(iter));
         e_iter.push_back(QString::number(iter));
         f_iter.push_back(QString::number(iter));
         g_iter.push_back(QString::number(iter));
         z_iter.push_back(QString::number(iter));
         xlsx.write(c_iter,this->plan_data[i].getIdPlan());
         xlsx.write(d_iter,this->plan_data[i].getKolHours());
         xlsx.write(e_iter,this->plan_data[i].getIdPredmet());
         xlsx.write(f_iter,this->plan_data[i].getTypeInt());
         xlsx.write(g_iter,QString::fromUtf8(this->plan_data[i].getNameGP().data(),this->plan_data[i].getNameGP().size()));
         xlsx.write(z_iter,this->plan_data[i].getIdTeacher());
     }
     for(int i=this->plan_data.size();i<1500;i++)
     {
         iter++;
         QString c_iter="C";
         QString d_iter="D";
         QString e_iter="E";
         QString f_iter="F";
         QString g_iter="G";
         QString z_iter="Z";
         c_iter.push_back(QString::number(iter));
         d_iter.push_back(QString::number(iter));
         e_iter.push_back(QString::number(iter));
         f_iter.push_back(QString::number(iter));
         g_iter.push_back(QString::number(iter));
         z_iter.push_back(QString::number(iter));
         xlsx.write(c_iter,"");
         xlsx.write(d_iter,"");
         xlsx.write(e_iter,"");
         xlsx.write(f_iter,"");
         xlsx.write(g_iter,"");
         xlsx.write(z_iter,"");
     }
     xlsx.saveAs("BD.xlsx");
}
void BD::sortPlan(){    std::sort(plan_data.begin(), plan_data.end());}
bool BD::addPlan(int i_id_predmet,int i_hours,int i_type,QString i_GP,int i_id_teacher)
{
    bool flag=false;
    Predmet iter;
    Teacher iter2;
    int buf=plan_data.size()+1;
    for(int i=0;i<predmet_data.size();i++)
        if(predmet_data[i].getIdPredmet()==i_id_predmet)
        {
            iter=predmet_data[i];
            for(int j=0;j<grupps_data.size();j++)
                if(grupps_data[j].getNameGrupp()==i_GP.toStdString()||grupps_data[j].getNumPotoka()==i_GP.toStdString())
                {
                    for(int x=0;x<teachers_data.size();x++)
                        if(teachers_data[x].getIdTeacher()==i_id_teacher){
                            iter2=teachers_data[x];
                            flag=true;
                            break;
                        }
                }
        }
    if(flag==false)
        return false;
    for(int i=0;i<plan_data.size();i++)
        if(i+1!=plan_data[i].getIdPlan())
        {
            buf=i+1;
            break;
        }
    Uchebni_plan *body=new Uchebni_plan(buf,i_hours,i_type,i_GP.toStdString(),iter,iter2);
    plan_data.push_back(*body);
    sortPlan();
    return true;
}
bool BD::deletePlan(int i_id)
{
    for(int i=0;i<plan_data.size();i++)
        if(i_id==plan_data[i].getIdPlan()){
            plan_data.removeAt(i);
            return true;
        }
    return false;
}
QList<Uchebni_plan> BD::getPlan(){    return this->plan_data;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BD::readGrupps(){
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffH,buffI,buffJ;
    int iter=1;
    QString h_iter="H2",i_iter,j_iter;
    buffH = xlsx.read(h_iter);
    if(buffH.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffH.toBool())
        {
            iter++;
            h_iter="H";
            i_iter="I";
            j_iter="J";
            h_iter.push_back(QString::number(iter));
            i_iter.push_back(QString::number(iter));
            j_iter.push_back(QString::number(iter));
            buffH = xlsx.read(h_iter);
            buffI = xlsx.read(i_iter);
            buffJ = xlsx.read(j_iter);
            if(!buffH.toBool())
                continue;
            Gruppa *Body = new Gruppa(buffH.toString().toStdString(),buffI.toInt(),buffJ.toString().toStdString());
            this->grupps_data.push_back(*Body);
        }
    }
    return;
}
void BD::writeGrupps(){
     QXlsx::Document xlsx("BD.xlsx");
     int iter=1;
     for(int i=0;i<this->grupps_data.size();i++)
     {
         iter++;
         QString h_iter="H";
         QString i_iter="I";
         QString j_iter="J";
         h_iter.push_back(QString::number(iter));
         i_iter.push_back(QString::number(iter));
         j_iter.push_back(QString::number(iter));
         xlsx.write(h_iter,QString::fromUtf8(this->grupps_data[i].getNameGrupp().data(),this->grupps_data[i].getNameGrupp().size()));
         xlsx.write(i_iter,this->grupps_data[i].getKolStud());
         xlsx.write(j_iter,QString::fromUtf8(this->grupps_data[i].getNumPotoka().data(),this->grupps_data[i].getNumPotoka().size()));
     }
     for(int i=this->grupps_data.size();i<1500;i++)
     {
         iter++;
         QString h_iter="H";
         QString i_iter="I";
         QString j_iter="J";
         h_iter.push_back(QString::number(iter));
         i_iter.push_back(QString::number(iter));
         j_iter.push_back(QString::number(iter));
         xlsx.write(h_iter,"");
         xlsx.write(i_iter,"");
         xlsx.write(j_iter,"");
     }
     xlsx.saveAs("BD.xlsx");
}
void BD::sortGrupps(){ std::sort(grupps_data.begin(), grupps_data.end());}
bool BD::addGrupp(QString i_name_grupp,int i_kol_stud,QString i_name_potok){
    bool flag=true;
    for(int i=0;i<grupps_data.size();i++)
        if(grupps_data[i].getNameGrupp()==i_name_grupp.toStdString())
            flag=false;
    if(flag==false)
        return false;
    Gruppa body(i_name_grupp.toStdString(),i_kol_stud,i_name_potok.toStdString());
    grupps_data.append(body);
    this->sortGrupps();
    return true;
}
bool BD::deleteGruppa(QString i_str)
{
    for(int i=0;i<grupps_data.size();i++)
        if(grupps_data[i].getNameGrupp()==i_str.toStdString()){
            grupps_data.removeAt(i);
            return true;
        }
    return false;
}
bool BD::rePotok(QString i_num_grupp,QString i_num_potok){
    for(int i=0;i<grupps_data.size();i++)
        if(grupps_data[i].getNameGrupp()==i_num_grupp.toStdString()){
            grupps_data[i].setPotok(i_num_potok.toStdString());
            return true;
        }
    return false;
}
QList<Gruppa> BD::getGrupps(){return this->grupps_data;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BD::readTeachers()
{
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffK,buffL,buffM,buffN;
    int iter=1;
    QString k_iter="K2",l_iter,m_iter,n_iter,buff;
    buffK = xlsx.read(k_iter);
    if(buffK.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffK.toBool())
        {
            iter++;
            k_iter="K";
            l_iter="L";
            m_iter="M";
            n_iter="N";
            k_iter.push_back(QString::number(iter));
            l_iter.push_back(QString::number(iter));
            m_iter.push_back(QString::number(iter));
            n_iter.push_back(QString::number(iter));
            buffK = xlsx.read(k_iter);
            buffL = xlsx.read(l_iter);
            buffM = xlsx.read(m_iter);
            buffN = xlsx.read(n_iter);
            if(!buffK.toBool())
                continue;

            Teacher *Body = new Teacher(buffK.toInt(),buffL.toString().toStdString(),buffM.toInt());
            for(int i=0;i<buffN.toString().size();i++)
            {
                if(buffN.toString()[i]==","||buffN.toString()[i]==";"){
                    for(int j=0;j<predmet_data.size();j++)
                        if(predmet_data[j].getIdPredmet()==buff.toInt())
                        {
                             Body->addPredmetIdInTeacher(buff.toInt());
                             break;
                        }
                    buff="";
                    continue;
                }
                buff+=buffN.toString()[i];
            }
            this->teachers_data.push_back(*Body);
        }
    }
    return;
}
void BD::writeTeachers(){
    QXlsx::Document xlsx("BD.xlsx");
    int iter=1;
    for(int i=0;i<this->teachers_data.size();i++)
    {
        iter++;
        QString k_iter="K";
        QString l_iter="L";
        QString m_iter="M";
        QString n_iter="N";
        QString str="";
        k_iter.push_back(QString::number(iter));
        l_iter.push_back(QString::number(iter));
        m_iter.push_back(QString::number(iter));
        n_iter.push_back(QString::number(iter));
        xlsx.write(k_iter,this->teachers_data[i].getIdTeacher());
        xlsx.write(l_iter,QString::fromUtf8(this->teachers_data[i].getNameTeather().data(),this->teachers_data[i].getNameTeather().size()));
        xlsx.write(m_iter,this->teachers_data[i].getPositionInt());
        for(int j=0;j<this->teachers_data[i].getPredmetIdInTeacher().size();j++)
        {
            str+=QString::number(this->teachers_data[i].getPredmetIdInTeacher()[j]);
            str+=",";
        }
        xlsx.write(n_iter,str);
    }
    for(int i=this->teachers_data.size();i<1500;i++)
    {
        iter++;
        QString k_iter="K";
        QString l_iter="L";
        QString m_iter="M";
        QString n_iter="N";
        k_iter.push_back(QString::number(iter));
        l_iter.push_back(QString::number(iter));
        m_iter.push_back(QString::number(iter));
        n_iter.push_back(QString::number(iter));
        xlsx.write(k_iter,"");
        xlsx.write(l_iter,"");
        xlsx.write(m_iter,"");
        xlsx.write(n_iter,"");
    }
    xlsx.saveAs("BD.xlsx");
}
void BD::sortTeachers(){    std::sort(teachers_data.begin(), teachers_data.end());}
void BD::addTeacher(std::string i_id, int i_p)
{
    int buf=teachers_data.size()+1;
    for(int i=0;i<teachers_data.size();i++)
        if(teachers_data[i].getIdTeacher()!=i+1)
        {
            buf=i+1;
            break;
        }
    Teacher *Body=new Teacher(buf,i_id,i_p);
    teachers_data.push_back(*Body);
    sortTeachers();
}
bool BD::deleteTeacher(int i_id)
{
    for(int i=0;i<teachers_data.size();i++)
        if(teachers_data[i].getIdTeacher()==i_id){
            teachers_data.removeAt(i);
            return true;
        }
    return false;
}
int BD::addPredmetInTeather(int i_id_teacher, int i_id_predmet){
    for(int i=0;i<teachers_data.size();i++)
    {
        if(i_id_teacher==teachers_data[i].getIdTeacher())
            for(int j=0;j<predmet_data.size();j++)
                if(i_id_predmet==predmet_data[j].getIdPredmet()){
                    for(int a=0;a<teachers_data[i].getPredmetIdInTeacher().size();a++)
                    {
                        if(i_id_predmet==teachers_data[i].getPredmetIdInTeacher()[a])
                            return 2;
                    }
                    teachers_data[i].addPredmetIdInTeacher(predmet_data[j].getIdPredmet());
                    return 0;
                }
    }
    return 1;
}
bool BD::deletePredmetInTeather(int i_id_teacher, int i_id_predmet){
    for(int i=0;i<teachers_data.size();i++)
    {
        if(i_id_teacher==teachers_data[i].getIdTeacher())
            for(int j=0;j<predmet_data.size();j++)
                if(i_id_predmet==predmet_data[j].getIdPredmet())
                    for(int a=0;a<teachers_data[i].getPredmetIdInTeacher().size();a++)
                    {
                        if(i_id_predmet==teachers_data[i].getPredmetIdInTeacher()[a]){
                            teachers_data[i].deletePredmetIdInTeacher(a);
                            return true;
                        }
                    }
    }
    return false;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BD::readCabs(){
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffO,buffP;
    int iter=1;
    QString a_iter="O2",b_iter;
    buffO = xlsx.read(a_iter);
    if(buffO.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffO.toBool())
        {
            iter++;
            a_iter="O";
            b_iter="P";
            a_iter.push_back(QString::number(iter));
            b_iter.push_back(QString::number(iter));
            buffO = xlsx.read(a_iter);
            buffP = xlsx.read(b_iter);
            if(!buffO.toBool())
                continue;
            Cabinet *Body = new Cabinet(buffO.toString().toStdString(),buffP.toInt());
            this->cabs_data.push_back(*Body);
        }
    }
    return;
}
void BD::writeCabs(){
    QXlsx::Document xlsx("BD.xlsx");
    int iter=1;
    for(int i=0;i<this->cabs_data.size();i++)
    {
        iter++;
        QString o_iter="O";
        QString p_iter="P";
        o_iter.push_back(QString::number(iter));
        p_iter.push_back(QString::number(iter));
        xlsx.write(o_iter,QString::fromUtf8(this->cabs_data[i].getCab().data(),this->cabs_data[i].getCab().size()));
        xlsx.write(p_iter,QString::number(this->cabs_data[i].getAddressInt()));
    }
    for(int i=this->teachers_data.size();i<1500;i++)
    {
        iter++;
        QString o_iter="O";
        QString p_iter="P";
        o_iter.push_back(QString::number(iter));
        p_iter.push_back(QString::number(iter));
        xlsx.write(o_iter,"");
        xlsx.write(p_iter,"");
    }
    xlsx.saveAs("BD.xlsx");
}
void BD::sortCabs(){ std::sort(cabs_data.begin(),cabs_data.end());}
bool BD::addCabs(std::string i_cab,int i_index){
    bool flag=true;
    for(int i=0;i<cabs_data.size();i++)
        if(cabs_data[i].getCab()==i_cab&&cabs_data[i].getAddressInt()==i_index)
            flag=false;
    if(flag==false)
        return false;
    Cabinet body(i_cab,i_index);
    cabs_data.append(body);
    this->sortCabs();
    return true;
}
bool BD::deleteCabs(std::string i_cab,int i_index){
    for(int i=0;i<cabs_data.size();i++)
        if(cabs_data[i].getCab()==i_cab&&cabs_data[i].getAddressInt()==i_index){
            cabs_data.removeAt(i);
            return true;
        }
    return false;
}
QList<Cabinet> BD::getCabs(){return this->cabs_data;}

QList<Teacher> BD::getTeachers(){return this->teachers_data;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BD::readLessons(){
    QXlsx::Document xlsx("BD.xlsx");
    QVariant buffQ,buffR,buffS,buffT,buffU,buffV,buffW,buffX,buffY;
    int iter=1;
    QString q_iter="Q2",r_iter,s_iter,t_iter,u_iter,v_iter,w_iter,x_iter,y_iter;
    Cabinet cabinet;
    Predmet pred;
    Teacher teacher;
    buffQ = xlsx.read(q_iter);
    if(buffQ.toBool())//Если значение 0 то отвал чипа (id не может быть 0 в моем случае)
    {
        while(buffQ.toBool())
        {
            iter++;
            q_iter="Q";//id
            r_iter="R";//day
            s_iter="S";//numpara
            t_iter="T";//type
            u_iter="U";//cab
            v_iter="V";//cab_index
            w_iter="W";//id_predmet
            x_iter="X";//id_teacher
            y_iter="Y";//nameGP
            q_iter.push_back(QString::number(iter));
            r_iter.push_back(QString::number(iter));
            s_iter.push_back(QString::number(iter));
            t_iter.push_back(QString::number(iter));
            u_iter.push_back(QString::number(iter));
            v_iter.push_back(QString::number(iter));
            w_iter.push_back(QString::number(iter));
            x_iter.push_back(QString::number(iter));
            y_iter.push_back(QString::number(iter));
            buffQ = xlsx.read(q_iter);
            buffR = xlsx.read(r_iter);
            buffS = xlsx.read(s_iter);
            buffT = xlsx.read(t_iter);
            buffU = xlsx.read(u_iter);
            buffV = xlsx.read(v_iter);
            buffW = xlsx.read(w_iter);
            buffX = xlsx.read(x_iter);
            buffY = xlsx.read(y_iter);
            if(!buffQ.toBool())
                continue;
            for(int i=0;i<cabs_data.size();i++)
                if(cabs_data[i].getCab()==buffU.toString().toStdString()&&cabs_data[i].getAddressInt()==buffV.toInt())
                    cabinet=cabs_data[i];
            for(int i=0;i<predmet_data.size();i++)
                if(predmet_data[i].getIdPredmet()==buffW.toInt())
                    pred=predmet_data[i];
            for(int i=0;i<teachers_data.size();i++)
                if(teachers_data[i].getIdTeacher()==buffX.toInt())
                    teacher=teachers_data[i];
            lesson body(buffQ.toInt(),buffR.toInt(),buffS.toInt(),buffT.toInt(),cabinet,pred,teacher,buffY.toString().toStdString());
            lessons_data.push_back(body);
        }
    }
    return;
}

void BD::writeLessons(){
    QXlsx::Document xlsx("BD.xlsx");
    int iter=1;
    for(int i=0;i<this->lessons_data.size();i++)
    {
        iter++;
        QString q_iter="Q";//id
        QString r_iter="R";//day
        QString s_iter="S";//numpara
        QString t_iter="T";//type
        QString u_iter="U";//cab
        QString v_iter="V";//cab_index
        QString w_iter="W";//id_predmet
        QString x_iter="X";//id_teacher
        QString y_iter="Y";//nameGP
        q_iter.push_back(QString::number(iter));
        r_iter.push_back(QString::number(iter));
        s_iter.push_back(QString::number(iter));
        t_iter.push_back(QString::number(iter));
        u_iter.push_back(QString::number(iter));
        v_iter.push_back(QString::number(iter));
        w_iter.push_back(QString::number(iter));
        x_iter.push_back(QString::number(iter));
        y_iter.push_back(QString::number(iter));
        xlsx.write(q_iter,QString::number(this->lessons_data[i].getIdLesson()));
        xlsx.write(r_iter,QString::number(this->lessons_data[i].getDays_in_weekInt()));
        xlsx.write(s_iter,QString::number(this->lessons_data[i].getNumberPara()));
        xlsx.write(t_iter,QString::number(this->lessons_data[i].getTypeInt()));
        xlsx.write(u_iter,QString::fromUtf8(this->lessons_data[i].getCab().data(),this->lessons_data[i].getCab().size()));
        xlsx.write(v_iter,QString::number(this->lessons_data[i].getAddressInt()));
        xlsx.write(w_iter,QString::number(this->lessons_data[i].getIdPredmet()));
        xlsx.write(x_iter,QString::number(this->lessons_data[i].getIdTeacher()));
        xlsx.write(y_iter,QString::fromUtf8(this->lessons_data[i].getName_GP().data(),this->lessons_data[i].getName_GP().size()));
    }
    for(int i=this->lessons_data.size();i<1500;i++)
    {
        iter++;
        QString q_iter="Q";//id
        QString r_iter="R";//day
        QString s_iter="S";//numpara
        QString t_iter="T";//type
        QString u_iter="U";//cab
        QString v_iter="V";//cab_index
        QString w_iter="W";//id_predmet
        QString x_iter="X";//id_teacher
        QString y_iter="Y";//nameGP
        q_iter.push_back(QString::number(iter));
        r_iter.push_back(QString::number(iter));
        s_iter.push_back(QString::number(iter));
        t_iter.push_back(QString::number(iter));
        u_iter.push_back(QString::number(iter));
        v_iter.push_back(QString::number(iter));
        w_iter.push_back(QString::number(iter));
        x_iter.push_back(QString::number(iter));
        y_iter.push_back(QString::number(iter));
        xlsx.write(q_iter,"");
        xlsx.write(r_iter,"");
        xlsx.write(s_iter,"");
        xlsx.write(t_iter,"");
        xlsx.write(u_iter,"");
        xlsx.write(v_iter,"");
        xlsx.write(w_iter,"");
        xlsx.write(x_iter,"");
        xlsx.write(y_iter,"");
    }
    xlsx.saveAs("BD.xlsx");
}
void BD::sortLessons(){ std::sort(lessons_data.begin(),lessons_data.end());}
int BD::addLesson(int i_day,int i_numPara,int i_type_lesson,int i_id_predmet,int i_id_teacher,int i_index_cab,QString i_cab,QString i_nameGP){
    bool flag=false;
    Predmet pred;
    Teacher teach;
    Cabinet cabinet;
    for(int i=0;i<predmet_data.size();i++)
        if(predmet_data[i].getIdPredmet()==i_id_predmet){
            pred=predmet_data[i];
            flag=true;
        }
    if(!flag)
        return 0;
    flag=false;
    for(int i=0;i<teachers_data.size();i++)
        if(teachers_data[i].getIdTeacher()==i_id_teacher){
            teach=teachers_data[i];
            flag=true;
        }
    if(!flag)
        return 1;
    flag=false;
    for(int i=0;i<cabs_data.size();i++)
        if(cabs_data[i].getAddressInt()==i_index_cab&&cabs_data[i].getCab()==i_cab.toStdString()){
            cabinet=cabs_data[i];
            flag=true;
        }
    if(!flag)
        return 2;
    flag=false;
    for(int i=0;i<grupps_data.size();i++)
        if(grupps_data[i].getNameGrupp()==i_nameGP.toStdString()||grupps_data[i].getNumPotoka()==i_nameGP.toStdString())
            flag=true;
    if(!flag)
        return 3;
    for(int i=0;i<lessons_data.size();i++)
        if(lessons_data[i].getDays_in_weekInt()==i_day&&lessons_data[i].getNumberPara()==i_numPara+1&&lessons_data[i].getAddressInt()==i_index_cab&&lessons_data[i].getCab()==i_cab.toStdString())
            return 4;
    for(int i=0;i<lessons_data.size();i++)
        if(lessons_data[i].getDays_in_weekInt()==i_day&&lessons_data[i].getNumberPara()==i_numPara+1&&lessons_data[i].getName_GP()==i_nameGP.toStdString())
            return 5;
    for(int i=0;i<lessons_data.size();i++)
        if(lessons_data[i].getDays_in_weekInt()==i_day&&lessons_data[i].getNumberPara()==i_numPara+1&&lessons_data[i].getIdTeacher()==i_id_teacher)
            return 6;

    int buff=lessons_data.size()+1;
    for(int i=0;i<lessons_data.size();i++)
        if(i+1!=lessons_data[i].getIdLesson()){
            buff=i+1;
            break;
        }
    lesson body(buff,i_day,i_numPara+1,i_type_lesson,cabinet,pred,teach,i_nameGP.toStdString());
    lessons_data.push_back(body);
    sortLessons();
    return 7;
}

bool BD::deleteLesson(int i_id){
    for(int i=0;i<lessons_data.size();i++)
        if(lessons_data[i].getIdLesson()==i_id){
            lessons_data.removeAt(i);
            return true;
        }
    return false;
}

void BD::deleteLessonAll(){
    int j=lessons_data.size();
    for(int i=0;i<j;i++)
        lessons_data.pop_back();
}
QList<lesson> BD::getLessons(){return lessons_data;}

void BD::GenerateTimeTable(){
    bool GP_wait,Teache_wait,Cab_wait;
    int kolPar;
    bool flag_add=false;
    for(int i=0;i<plan_data.size();i++){
        kolPar=div(plan_data[i].getKolHours(),34).quot;
        if(div(plan_data[i].getKolHours(),34).rem!=0)
            kolPar++;
        for(int j=0;j<kolPar;j++){
            flag_add=false;
            for(int day=0;day<6;day++){
                //найти группы и поток
                for(int para=1;para<7;para++){
                    QList<std::string> Grup;
                    std::string Potok;
                    if(plan_data[i].getNameGP()[0]=='P'){
                        Potok=plan_data[i].getNameGP();
                        for(int x=0;x<grupps_data.size();x++)
                            if(grupps_data[x].getNumPotoka()==Potok)
                                Grup.push_back(grupps_data[x].getNameGrupp());
                    }
                    else{
                        for(int x=0;x<grupps_data.size();x++)
                            if(grupps_data[x].getNameGrupp()==plan_data[i].getNameGP())
                               Potok=grupps_data[x].getNumPotoka();
                        for(int x=0;x<grupps_data.size();x++)
                            if(grupps_data[x].getNumPotoka()==Potok)
                                Grup.push_back(grupps_data[x].getNameGrupp());
                    }
                    //проверки
                    GP_wait=this->wainGP(Grup,Potok,day,para);
                    Teache_wait=this->waitTeacher(plan_data[i].getIdTeacher(),day,para);
                    Cab_wait=this->waitCabinet(day,para);
                    if(GP_wait||Teache_wait||Cab_wait)
                        continue;
                    int buff=lessons_data.size()+1;
                    for(int q=0;q<lessons_data.size();q++)
                        if(q+1!=lessons_data[q].getIdLesson()){
                            buff=q+1;
                            break;
                        }
                    Cabinet buff_cab;
                    Predmet buff_predmet;
                    Teacher buff_teacher;
                    for(int cab=0;cab<cabs_data.size();cab++){
                        bool flag_cab=true;
                        for(int p=0;p<lessons_data.size();p++){
                            if(cabs_data[cab].getCab()==lessons_data[p].getCab()&&cabs_data[cab].getAddressInt()==lessons_data[p].getAddressInt()&&day==lessons_data[p].getDays_in_weekInt()&&para==lessons_data[p].getNumberPara())
                                flag_cab=false;
                        }
                        if(flag_cab==true){
                            buff_cab=cabs_data[cab];
                            break;
                        }
                    }
                    for(int q=0;q<predmet_data.size();q++)
                        if(plan_data[i].getIdPredmet()==predmet_data[q].getIdPredmet())
                            buff_predmet=predmet_data[q];
                    for(int q=0;q<teachers_data.size();q++)
                        if(plan_data[i].getIdTeacher()==teachers_data[q].getIdTeacher())
                            buff_teacher=teachers_data[q];

                    lesson body(buff,day,para,plan_data[i].getTypeInt(),buff_cab,buff_predmet,buff_teacher,plan_data[i].getNameGP());
                    lessons_data.push_back(body);
                    sortLessons();
                    flag_add=true;
                    break;
                }
                if(flag_add)
                    break;
            }
        }
    }
}

QList<lesson> BD::FindLessons(QString i_str,int index_day){
    bool flag=false;
    QList<lesson> buff;
    for(int i=0;i<grupps_data.size();i++){
        if(i_str.toStdString()==grupps_data[i].getNameGrupp())
            flag=true;
    }
    if(flag){
        std::string Potok;
        for(int x=0;x<grupps_data.size();x++)
            if(grupps_data[x].getNameGrupp()==i_str.toStdString())
                 Potok=grupps_data[x].getNumPotoka();
        for(int i=0;i<lessons_data.size();i++)
            if(lessons_data[i].getName_GP()==i_str.toStdString()&&lessons_data[i].getDays_in_weekInt()==index_day||lessons_data[i].getName_GP()==Potok&&lessons_data[i].getDays_in_weekInt()==index_day)
                buff.push_back(lessons_data[i]);
        return buff;

    }
    else{
        int id_t;
        for(int i=0;i<teachers_data.size();i++)
            if(i_str.toStdString()==teachers_data[i].getNameTeather()){
                id_t=teachers_data[i].getIdTeacher();
                flag=true;
            }
        if(flag){
            for(int i=0;i<lessons_data.size();i++)
                if(lessons_data[i].getIdTeacher()==id_t&&lessons_data[i].getDays_in_weekInt()==index_day)
                    buff.push_back(lessons_data[i]);
            return buff;
        }
        else{
            return buff;
        }
    }
}
