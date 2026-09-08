export type LanguageCode = 'es' | 'en' | 'de' | 'fr' | 'ru';
export type ThemeMode = 'dark' | 'light';

export interface LanguageOption {
  code: LanguageCode;
  shortLabel: string;
  nativeLabel: string;
  locale: string;
  flag: string;
}

type UiTextTranslations = Record<LanguageCode, string>;

type ContentTranslationEntry = {
  es: string;
} & Record<Exclude<LanguageCode, 'es'>, string>;

export const LANGUAGE_OPTIONS: LanguageOption[] = [
  { code: 'es', shortLabel: 'ES', nativeLabel: 'Español', locale: 'es-MX', flag: 'assets/flags/ES.webp' },
  { code: 'en', shortLabel: 'EN', nativeLabel: 'English', locale: 'en-US', flag: 'assets/flags/EN.webp' },
  { code: 'de', shortLabel: 'DE', nativeLabel: 'Deutsch', locale: 'de-DE', flag: 'assets/flags/DE.webp' },
  { code: 'fr', shortLabel: 'FR', nativeLabel: 'Français', locale: 'fr-FR', flag: 'assets/flags/FR.webp' },
  { code: 'ru', shortLabel: 'RU', nativeLabel: 'Русский', locale: 'ru-RU', flag: 'assets/flags/RU.webp' }
];

export const UI_TEXTS = {
  'nav.projects': {
    es: 'Proyectos',
    en: 'Projects',
    de: 'Projekte',
    fr: 'Projets',
    ru: 'Проекты'
  },
  'nav.experience': {
    es: 'Experiencia',
    en: 'Experience',
    de: 'Erfahrung',
    fr: 'Expérience',
    ru: 'Опыт'
  },
  'nav.education': {
    es: 'Formación',
    en: 'Education',
    de: 'Ausbildung',
    fr: 'Formation',
    ru: 'Образование'
  },
  'nav.profile': {
    es: 'Perfil',
    en: 'Profile',
    de: 'Profil',
    fr: 'Profil',
    ru: 'Профиль'
  },
  'nav.contact': {
    es: 'Contacto',
    en: 'Contact',
    de: 'Kontakt',
    fr: 'Contact',
    ru: 'Контакты'
  },
  'header.role.long': {
    es: 'Ingeniero en Ciencias de la Computación',
    en: 'Computer Science Engineer',
    de: 'Ingenieur für Informatik',
    fr: 'Ingénieur en informatique',
    ru: 'Инженер по компьютерным наукам'
  },
  'header.role.short': {
    es: 'Ing. en Cs. de la Computación',
    en: 'Computer Science Eng.',
    de: 'Ing. für Informatik',
    fr: 'Ing. en informatique',
    ru: 'Инж. по компьютерным наукам'
  },
  'header.pressMenu': {
    es: 'Presiona para ver el menú',
    en: 'Tap to open the menu',
    de: 'Tippe, um das Menü zu öffnen',
    fr: 'Touchez pour ouvrir le menu',
    ru: 'Нажмите, чтобы открыть меню'
  },
  'section.pressDice': {
    es: 'Presiona los dados para ver el menú',
    en: 'Tap the dice to open the menu',
    de: 'Tippe auf die Würfel, um das Menü zu öffnen',
    fr: 'Touchez les dés pour ouvrir le menu',
    ru: 'Нажмите на кости, чтобы открыть меню'
  },
  'header.angularBuilt': {
    es: 'hecho con Angular',
    en: 'built with Angular',
    de: 'mit Angular erstellt',
    fr: 'réalisé avec Angular',
    ru: 'сделано на Angular'
  },
  'theme.toggle': {
    es: 'Cambiar tema',
    en: 'Toggle theme',
    de: 'Thema wechseln',
    fr: 'Changer de thème',
    ru: 'Сменить тему'
  },
  'theme.dark': {
    es: 'Tema oscuro',
    en: 'Dark theme',
    de: 'Dunkles Thema',
    fr: 'Thème sombre',
    ru: 'Темная тема'
  },
  'theme.light': {
    es: 'Tema claro',
    en: 'Light theme',
    de: 'Helles Thema',
    fr: 'Thème clair',
    ru: 'Светлая тема'
  },
  'theme.switchToLight': {
    es: 'Cambiar a tema claro',
    en: 'Switch to light theme',
    de: 'Zum hellen Thema wechseln',
    fr: 'Passer au thème clair',
    ru: 'Переключить на светлую тему'
  },
  'theme.switchToDark': {
    es: 'Cambiar a tema oscuro',
    en: 'Switch to dark theme',
    de: 'Zum dunklen Thema wechseln',
    fr: 'Passer au thème sombre',
    ru: 'Переключить на темную тему'
  },
  'language.label': {
    es: 'Idioma',
    en: 'Language',
    de: 'Sprache',
    fr: 'Langue',
    ru: 'Язык'
  },
  'language.open': {
    es: 'Seleccionar idioma',
    en: 'Choose language',
    de: 'Sprache auswählen',
    fr: 'Choisir la langue',
    ru: 'Выбрать язык'
  },
  'footer.version': {
    es: 'Versión',
    en: 'Version',
    de: 'Version',
    fr: 'Version',
    ru: 'Версия'
  },
  'projects.more': {
    es: 'Ver más',
    en: 'See more',
    de: 'Mehr sehen',
    fr: 'Voir plus',
    ru: 'Подробнее'
  },
  'projects.badge.monetized': {
    es: 'Monetizado / comercial',
    en: 'Monetized / commercial',
    de: 'Monetarisiert / kommerziell',
    fr: 'Monétisé / commercial',
    ru: 'Монетизировано / коммерческое'
  },
  'projects.badge.favorite': {
    es: 'Favorito',
    en: 'Favorite',
    de: 'Favorit',
    fr: 'Favori',
    ru: 'Любимый'
  },
  'projects.badge.individual': {
    es: 'Individual',
    en: 'Solo',
    de: 'Einzeln',
    fr: 'Individuel',
    ru: 'Индивидуальный'
  },
  'projects.badge.team': {
    es: 'En equipo / colaboración',
    en: 'Teamwork / collaboration',
    de: 'Teamarbeit / Zusammenarbeit',
    fr: 'Travail en équipe / collaboration',
    ru: 'Командная работа / сотрудничество'
  },
  'projects.badge.inProgress': {
    es: 'En desarrollo',
    en: 'In progress',
    de: 'In Entwicklung',
    fr: 'En cours',
    ru: 'В разработке'
  },
  'projects.badge.personal': {
    es: 'Personal',
    en: 'Personal',
    de: 'Persönlich',
    fr: 'Personnel',
    ru: 'Личный'
  },
  'projects.badge.experimental': {
    es: 'Experimental / aprendizaje / investigación',
    en: 'Experimental / learning / research',
    de: 'Experimentell / Lernen / Forschung',
    fr: 'Expérimental / apprentissage / recherche',
    ru: 'Эксперимент / обучение / исследование'
  },
  'projects.badge.academic': {
    es: 'Académico',
    en: 'Academic',
    de: 'Akademisch',
    fr: 'Académique',
    ru: 'Академический'
  },
  'projects.badge.industrial': {
    es: 'Industrial',
    en: 'Industrial',
    de: 'Industriell',
    fr: 'Industriel',
    ru: 'Промышленный'
  },
  'projects.badge.businessCorporate': {
    es: 'Empresarial / corporativo',
    en: 'Business / corporate',
    de: 'Geschäftlich / unternehmerisch',
    fr: 'Entreprise / corporate',
    ru: 'Деловой / корпоративный'
  },
  'projects.badge.administrative': {
    es: 'Administrativo',
    en: 'Administrative',
    de: 'Administrativ',
    fr: 'Administratif',
    ru: 'Административный'
  },
  'projects.badge.independent': {
    es: 'Independiente',
    en: 'Independent',
    de: 'Unabhängig',
    fr: 'Indépendant',
    ru: 'Независимый'
  },
  'projects.badge.production': {
    es: 'Para producción / en operación',
    en: 'For production / in operation',
    de: 'Für Produktion / im Betrieb',
    fr: 'Pour la production / en fonctionnement',
    ru: 'Для производства / в работе'
  },
  'projects.badge.active': {
    es: 'Activo / Vigente',
    en: 'Active / Current',
    de: 'Aktiv / Gültig',
    fr: 'Actif / En vigueur',
    ru: 'Активный / актуальный'
  },
  'projects.badge.standByPaused': {
    es: 'Stand By / pausado',
    en: 'Standby / paused',
    de: 'Stand-by / pausiert',
    fr: 'En veille / en pause',
    ru: 'Ожидание / приостановлено'
  },
  'projects.badge.clientCommission': {
    es: 'Cliente / encargo',
    en: 'Client / commission',
    de: 'Kunde / Auftrag',
    fr: 'Client / commande',
    ru: 'Клиент / заказ'
  },
  'projects.badge.publishedDistributed': {
    es: 'Publicado / distribuido',
    en: 'Published / distributed',
    de: 'Veröffentlicht / verteilt',
    fr: 'Publié / distribué',
    ru: 'Опубликовано / распространено'
  },
  'projects.badge.openSource': {
    es: 'Open source',
    en: 'Open source',
    de: 'Open Source',
    fr: 'Open source',
    ru: 'Открытый исходный код'
  },
  'projects.badge.closedSource': {
    es: 'Closed Source',
    en: 'Closed Source',
    de: 'Closed Source',
    fr: 'Code source fermé',
    ru: 'Закрытый исходный код'
  },
  'projects.badge.confidentialReserved': {
    es: 'Confidencial / información reservada',
    en: 'Confidential / restricted information',
    de: 'Vertraulich / reservierte Informationen',
    fr: 'Confidentiel / informations réservées',
    ru: 'Конфиденциально / закрытая информация'
  },
  'projects.badge.userTraining': {
    es: 'Incluyó/Implicó capacitación de usuarios',
    en: 'Included / implied user training',
    de: 'Umfasste / erforderte Benutzerschulung',
    fr: 'A inclus / impliqué une formation des utilisateurs',
    ru: 'Включало / подразумевало обучение пользователей'
  },
  'projects.badge.educational': {
    es: 'Educativo',
    en: 'Educational',
    de: 'Bildungsbezogen',
    fr: 'Éducatif',
    ru: 'Образовательный'
  },
  'projects.badge.legacy': {
    es: 'Legacy / base preexistente / desarrollo heredado',
    en: 'Legacy / pre-existing base / inherited development',
    de: 'Legacy / bestehende Basis / geerbte Entwicklung',
    fr: 'Legacy / base préexistante / développement hérité',
    ru: 'Legacy / существующая база / унаследованная разработка'
  },
  'projects.distribution.github': {
    es: 'Disponible en GitHub',
    en: 'Available on GitHub',
    de: 'Auf GitHub verfügbar',
    fr: 'Disponible sur GitHub',
    ru: 'Доступно на GitHub'
  },
  'projects.distribution.googlePlay': {
    es: 'Disponible en Google Play',
    en: 'Available on Google Play',
    de: 'Bei Google Play verfügbar',
    fr: 'Disponible sur Google Play',
    ru: 'Доступно в Google Play'
  },
  'projects.distribution.microsoftStore': {
    es: 'Disponible en Microsoft Store',
    en: 'Available on Microsoft Store',
    de: 'Im Microsoft Store verfügbar',
    fr: 'Disponible sur Microsoft Store',
    ru: 'Доступно в Microsoft Store'
  },
  'projects.distribution.magazine': {
    es: 'Revista científica/tecnológica o publicación oficial',
    en: 'Scientific/technology magazine or official publication',
    de: 'Wissenschaftliche/technologische Zeitschrift oder offizielle Publikation',
    fr: 'Revue scientifique/technologique ou publication officielle',
    ru: 'Научный/технологический журнал или официальная публикация'
  },
  'projects.distribution.web': {
    es: 'Disponible en web',
    en: 'Available on the web',
    de: 'Im Web verfügbar',
    fr: 'Disponible sur le web',
    ru: 'Доступно в интернете'
  },
  'projects.distribution.cloud': {
    es: 'Disponible en la nube',
    en: 'Available in the cloud',
    de: 'In der Cloud verfügbar',
    fr: 'Disponible dans le cloud',
    ru: 'Доступно в облаке'
  },
  'projects.tech.desktopApps': {
    es: 'Aplicaciones de escritorio',
    en: 'Desktop applications',
    de: 'Desktop-Anwendungen',
    fr: 'Applications de bureau',
    ru: 'Настольные приложения'
  },
  'projects.tech.mobileApps': {
    es: 'Aplicaciones móviles',
    en: 'Mobile applications',
    de: 'Mobile Anwendungen',
    fr: 'Applications mobiles',
    ru: 'Мобильные приложения'
  },
  'projects.tech.webDevelopment': {
    es: 'Desarrollo web',
    en: 'Web development',
    de: 'Webentwicklung',
    fr: 'Développement web',
    ru: 'Веб-разработка'
  },
  'projects.tech.databases': {
    es: 'Bases de datos',
    en: 'Databases',
    de: 'Datenbanken',
    fr: 'Bases de données',
    ru: 'Базы данных'
  },
  'projects.tech.dataScience': {
    es: 'Datos / análisis de datos / ciencia de datos',
    en: 'Data / data analysis / data science',
    de: 'Daten / Datenanalyse / Data Science',
    fr: 'Données / analyse de données / science des données',
    ru: 'Данные / анализ данных / наука о данных'
  },
  'projects.tech.ai': {
    es: 'IA - Inteligencia Artificial',
    en: 'AI - Artificial Intelligence',
    de: 'KI - Künstliche Intelligenz',
    fr: 'IA - Intelligence artificielle',
    ru: 'ИИ - Искусственный интеллект'
  },
  'projects.tech.ml': {
    es: 'ML - Machine Learning',
    en: 'ML - Machine Learning',
    de: 'ML - Maschinelles Lernen',
    fr: 'ML - Machine learning',
    ru: 'ML - Машинное обучение'
  },
  'projects.tech.llm': {
    es: 'LLM - Modelos de Lenguaje',
    en: 'LLM - Language Models',
    de: 'LLM - Sprachmodelle',
    fr: 'LLM - Modèles de langage',
    ru: 'LLM - Языковые модели'
  },
  'projects.tech.cybersecurity': {
    es: 'Ciberseguridad',
    en: 'Cybersecurity',
    de: 'Cybersicherheit',
    fr: 'Cybersécurité',
    ru: 'Кибербезопасность'
  },
  'projects.tech.games': {
    es: 'Videojuegos',
    en: 'Video games',
    de: 'Videospiele',
    fr: 'Jeux vidéo',
    ru: 'Видеоигры'
  },
  'projects.tech.multimedia': {
    es: 'Multimedia',
    en: 'Multimedia',
    de: 'Multimedia',
    fr: 'Multimédia',
    ru: 'Мультимедиа'
  },
  'projects.tech.documentation': {
    es: 'Contenido técnico / documentación',
    en: 'Technical content / documentation',
    de: 'Technischer Inhalt / Dokumentation',
    fr: 'Contenu technique / documentation',
    ru: 'Технический контент / документация'
  },
  'projects.tech.cloud': {
    es: 'Nube / computación en la nube',
    en: 'Cloud / cloud computing',
    de: 'Cloud / Cloud-Computing',
    fr: 'Cloud / informatique en nuage',
    ru: 'Облако / облачные вычисления'
  },
  'projects.tech.hardware': {
    es: 'Hardware',
    en: 'Hardware',
    de: 'Hardware',
    fr: 'Matériel',
    ru: 'Оборудование'
  },
  'projects.tech.office': {
    es: 'Ofimática',
    en: 'Office tools',
    de: 'Office-Anwendungen',
    fr: 'Bureautique',
    ru: 'Офисные инструменты'
  },
  'projects.tech.embeddedSystems': {
    es: 'Sistemas embebidos',
    en: 'Embedded systems',
    de: 'Eingebettete Systeme',
    fr: 'Systèmes embarqués',
    ru: 'Встраиваемые системы'
  },
  'projects.tech.networks': {
    es: 'Redes',
    en: 'Networks',
    de: 'Netzwerke',
    fr: 'Réseaux',
    ru: 'Сети'
  },
  'projects.tech.backend': {
    es: 'Backend',
    en: 'Backend',
    de: 'Backend',
    fr: 'Backend',
    ru: 'Бэкенд'
  },
  'projects.tech.frontend': {
    es: 'Frontend',
    en: 'Frontend',
    de: 'Frontend',
    fr: 'Frontend',
    ru: 'Фронтенд'
  },
  'projects.tech.automation': {
    es: 'Automatización',
    en: 'Automation',
    de: 'Automatisierung',
    fr: 'Automatisation',
    ru: 'Автоматизация'
  },
  'projects.tech.servers': {
    es: 'servidor / servidores',
    en: 'server / servers',
    de: 'Server / Server',
    fr: 'serveur / serveurs',
    ru: 'сервер / серверы'
  },
  'projects.tech.android': {
    es: 'Android',
    en: 'Android',
    de: 'Android',
    fr: 'Android',
    ru: 'Android'
  },
  'projects.tech.windows': {
    es: 'Windows',
    en: 'Windows',
    de: 'Windows',
    fr: 'Windows',
    ru: 'Windows'
  },
  'projects.tech.linux': {
    es: 'Linux',
    en: 'Linux',
    de: 'Linux',
    fr: 'Linux',
    ru: 'Linux'
  },
  'experience.from': {
    es: 'de',
    en: 'from',
    de: 'von',
    fr: 'de',
    ru: 'с'
  },
  'experience.to': {
    es: 'a',
    en: 'to',
    de: 'bis',
    fr: 'à',
    ru: 'по'
  },
  'experience.present': {
    es: 'Actualidad',
    en: 'Present',
    de: 'Heute',
    fr: 'Actuel',
    ru: 'Настоящее время'
  },
  'experience.location': {
    es: 'Ubicación',
    en: 'Location',
    de: 'Standort',
    fr: 'Localisation',
    ru: 'Локация'
  },
  'experience.notApplicable': {
    es: 'No aplica',
    en: 'Not applicable',
    de: 'Nicht zutreffend',
    fr: 'Sans objet',
    ru: 'Не применяется'
  },
  'experience.visitLocation': {
    es: 'Visitar ubicación',
    en: 'Open location',
    de: 'Standort öffnen',
    fr: 'Voir la localisation',
    ru: 'Открыть локацию'
  },
  'experience.moreInfo': {
    es: 'Más información',
    en: 'More information',
    de: 'Mehr Informationen',
    fr: "Plus d'informations",
    ru: 'Подробнее'
  },
  'experience.responsibilities': {
    es: 'Responsabilidades',
    en: 'Responsibilities',
    de: 'Verantwortlichkeiten',
    fr: 'Responsabilités',
    ru: 'Обязанности'
  },
  'experience.achievements': {
    es: 'Logros',
    en: 'Achievements',
    de: 'Erfolge',
    fr: 'Réalisations',
    ru: 'Достижения'
  },
  'education.from': {
    es: 'de',
    en: 'from',
    de: 'von',
    fr: 'de',
    ru: 'с'
  },
  'education.to': {
    es: 'a',
    en: 'to',
    de: 'bis',
    fr: 'à',
    ru: 'по'
  },
  'education.present': {
    es: 'Actualidad',
    en: 'Present',
    de: 'Heute',
    fr: 'Actuel',
    ru: 'Настоящее время'
  },
  'education.moreInfo': {
    es: 'Más información',
    en: 'More information',
    de: 'Mehr Informationen',
    fr: "Plus d'informations",
    ru: 'Подробнее'
  },
  'profile.heading': {
    es: '☼ PERFIL',
    en: '☼ PROFILE',
    de: '☼ PROFIL',
    fr: '☼ PROFIL',
    ru: '☼ ПРОФИЛЬ'
  },
  'profile.summary': {
    es: 'Mis mayores fortalezas son la creatividad y el ingenio, mi principal valor es el compromiso. En el ámbito profesional soy una persona cautelosa y metódica. Dedico tiempo a comprender a fondo los problemas y proponer soluciones eficaces. Cuando realizo trabajo de investigación, mi prioridad es simplificar cuestiones que puedan ser complicadas. Aunque prefiero tareas que ya manejo con soltura y cuya ejecución es principalmente rutinaria, aunque sea un poco más monótono, me considero más eficiente en esas tareas. Aprecio la comunicación efectiva y transparente, reconozco la importancia del trabajo en equipo. Al trabajar en Front-end me apasiona crear diseños claros y visualmente atractivos para los usuarios finales. Y procuro crear documentaciones fáciles de entender para mis colegas.',
    en: 'My greatest strengths are creativity and resourcefulness, and my core value is commitment. Professionally, I am cautious and methodical. I invest time in understanding problems deeply and proposing effective solutions. When I do research work, my priority is to simplify topics that could otherwise feel complex. Although I prefer tasks I already handle comfortably and whose execution is mostly routine, even if a bit more monotonous, I consider myself more efficient in that kind of work. I value clear and transparent communication and recognize the importance of teamwork. In Front-end work, I enjoy creating clean and visually appealing designs for end users, and I try to produce documentation that is easy for teammates to understand.',
    de: 'Meine größten Stärken sind Kreativität und Einfallsreichtum, und mein wichtigster Wert ist Engagement. Beruflich bin ich vorsichtig und methodisch. Ich nehme mir Zeit, Probleme gründlich zu verstehen und wirksame Lösungen vorzuschlagen. Wenn ich Forschungsarbeit leiste, ist es meine Priorität, komplexe Themen zu vereinfachen. Obwohl ich Aufgaben bevorzuge, die ich bereits sicher beherrsche und die überwiegend routinemäßig sind, auch wenn sie etwas monotoner sind, halte ich mich gerade darin für besonders effizient. Ich schätze klare und transparente Kommunikation und erkenne die Bedeutung von Teamarbeit an. Im Frontend begeistert es mich, klare und visuell ansprechende Designs für Endnutzer zu schaffen, und ich versuche, Dokumentationen zu erstellen, die für Kolleginnen und Kollegen leicht verständlich sind.',
    fr: "Mes plus grandes forces sont la créativité et l'ingéniosité, et ma valeur principale est l'engagement. Sur le plan professionnel, je suis une personne prudente et méthodique. Je consacre du temps à comprendre les problèmes en profondeur et à proposer des solutions efficaces. Lorsque je réalise un travail de recherche, ma priorité est de simplifier des sujets qui pourraient être compliqués. Même si je préfère les tâches que je maîtrise déjà bien et dont l'exécution est surtout routinière, même si elles sont un peu plus monotones, je me considère plus efficace dans ce type de travail. J'apprécie une communication claire et transparente et je reconnais l'importance du travail en équipe. En front-end, j'aime créer des interfaces claires et visuellement attrayantes pour les utilisateurs finaux, et je m'efforce de produire une documentation facile à comprendre pour mes collègues.",
    ru: 'Мои главные сильные стороны - креативность и находчивость, а моя основная ценность - ответственность и вовлеченность. В профессиональной среде я осторожный и методичный человек. Я уделяю время тому, чтобы глубоко понять проблему и предложить эффективные решения. Когда я занимаюсь исследовательской работой, мой приоритет - упрощать темы, которые могут казаться сложными. Хотя я предпочитаю задачи, которыми уже уверенно владею и выполнение которых в основном рутинное, пусть и немного более монотонное, именно в такой работе я считаю себя особенно эффективным. Я ценю ясную и прозрачную коммуникацию и понимаю важность командной работы. Во фронтенде мне нравится создавать понятные и визуально привлекательные решения для конечных пользователей, а также писать документацию, которую коллегам легко понять.'
  },
  'profile.softSkills': {
    es: 'Habilidades blandas',
    en: 'Soft skills',
    de: 'Soft Skills',
    fr: 'Compétences humaines',
    ru: 'Гибкие навыки'
  },
  'profile.languages': {
    es: 'Lenguajes de programacion',
    en: 'Programming languages',
    de: 'Programmiersprachen',
    fr: 'Langages de programmation',
    ru: 'Языки программирования'
  },
  'profile.development': {
    es: 'Desarrollo',
    en: 'Development',
    de: 'Entwicklung',
    fr: 'Développement',
    ru: 'Разработка'
  },
  'profile.dataCloud': {
    es: 'Bases de datos y servicios en la nube',
    en: 'Databases and cloud services',
    de: 'Datenbanken und Cloud-Dienste',
    fr: 'Bases de données et services cloud',
    ru: 'Базы данных и облачные сервисы'
  },
  'profile.theory': {
    es: 'Teoría y fundamentos',
    en: 'Theory and fundamentals',
    de: 'Theorie und Grundlagen',
    fr: 'Théorie et fondamentaux',
    ru: 'Теория и основы'
  },
  'profile.infrastructure': {
    es: 'Infraestructura tecnológica, técnica y habilidades complementarias',
    en: 'Technical infrastructure and complementary skills',
    de: 'Technische Infrastruktur und ergänzende Fähigkeiten',
    fr: 'Infrastructure technique et compétences complémentaires',
    ru: 'Техническая инфраструктура и дополнительные навыки'
  },
  'profile.valuesTitle': {
    es: 'Valores y rasgos dominantes',
    en: 'Dominant values and traits',
    de: 'Dominante Werte und Merkmale',
    fr: 'Valeurs et traits dominants',
    ru: 'Доминирующие ценности и черты'
  },
  'profile.valuesNote': {
    es: '(Resultados de una prueba psicométrica obtenidos a través de una evaluación en Computrabajo, en diciembre de 2024).',
    en: '(Results from a psychometric test obtained through a Computrabajo assessment in December 2024).',
    de: '(Ergebnisse eines psychometrischen Tests aus einer Computrabajo-Bewertung im Dezember 2024).',
    fr: '(Résultats d’un test psychométrique obtenus via une évaluation Computrabajo en décembre 2024).',
    ru: '(Результаты психометрического теста, полученные в рамках оценки Computrabajo в декабре 2024 года).'
  },
  'contact.copied': {
    es: '✓ Copiado',
    en: '✓ Copied',
    de: '✓ Kopiert',
    fr: '✓ Copié',
    ru: '✓ Скопировано'
  },
  'contact.copyBusinessEmail': {
    es: '⧉ Copiar correo de negocios',
    en: '⧉ Copy business email',
    de: '⧉ Geschaefts-E-Mail kopieren',
    fr: "⧉ Copier l'e-mail professionnel de l'entreprise",
    ru: '⧉ Скопировать рабочую почту компании'
  },
  'contact.copyProfessionalEmail': {
    es: '⧉ Copiar correo profesional',
    en: '⧉ Copy professional email',
    de: '⧉ Berufliche E-Mail kopieren',
    fr: "⧉ Copier l'e-mail professionnel",
    ru: '⧉ Скопировать рабочую почту'
  },
  'contact.copyPhone': {
    es: '⧉ Copiar teléfono personal',
    en: '⧉ Copy personal phone',
    de: '⧉ Private Telefonnummer kopieren',
    fr: '⧉ Copier le téléphone personnel',
    ru: '⧉ Скопировать личный телефон'
  },
  'contact.copyLinkedIn': {
    es: '⧉ Copiar perfil de LinkedIn',
    en: '⧉ Copy LinkedIn profile',
    de: '⧉ LinkedIn-Profil kopieren',
    fr: '⧉ Copier le profil LinkedIn',
    ru: '⧉ Скопировать профиль LinkedIn'
  },
  'contact.copyGitHub': {
    es: '⧉ Copiar perfil de GitHub',
    en: '⧉ Copy GitHub profile',
    de: '⧉ GitHub-Profil kopieren',
    fr: '⧉ Copier le profil GitHub',
    ru: '⧉ Скопировать профиль GitHub'
  },
  'contact.businessEmail': {
    es: 'Correo de negocios',
    en: 'Business email',
    de: 'Geschaefts-E-Mail',
    fr: "E-mail professionnel de l'entreprise",
    ru: 'Рабочая почта компании'
  },
  'contact.professionalEmail': {
    es: 'Correo profesional',
    en: 'Professional email',
    de: 'Berufliche E-Mail',
    fr: 'E-mail professionnel',
    ru: 'Рабочая почта'
  },
  'contact.personalPhone': {
    es: 'Teléfono personal',
    en: 'Personal phone',
    de: 'Private Telefonnummer',
    fr: 'Téléphone personnel',
    ru: 'Личный телефон'
  },
  'contact.linkedin': {
    es: 'Perfil de LinkedIn',
    en: 'LinkedIn profile',
    de: 'LinkedIn-Profil',
    fr: 'Profil LinkedIn',
    ru: 'Профиль LinkedIn'
  },
  'contact.github': {
    es: 'Perfil de GitHub',
    en: 'GitHub profile',
    de: 'GitHub-Profil',
    fr: 'Profil GitHub',
    ru: 'Профиль GitHub'
  },
  'contact.sendBusinessEmail': {
    es: 'Enviar correo a',
    en: 'Send email to',
    de: 'E-Mail senden an',
    fr: 'Envoyer un e-mail à',
    ru: 'Отправить письмо на'
  },
  'contact.sendProfessionalEmail': {
    es: 'Enviar correo a',
    en: 'Send email to',
    de: 'E-Mail senden an',
    fr: 'Envoyer un e-mail à',
    ru: 'Отправить письмо на'
  },
  'contact.sendWhatsapp': {
    es: 'Enviar Whatsapp a',
    en: 'Send WhatsApp to',
    de: 'WhatsApp senden an',
    fr: 'Envoyer un WhatsApp à',
    ru: 'Отправить WhatsApp'
  },
  'contact.visit': {
    es: 'Visitar',
    en: 'Visit',
    de: 'Besuchen',
    fr: 'Visiter',
    ru: 'Открыть'
  },
  'contact.mailSubject': {
    es: 'Mensaje de contacto',
    en: 'Contact message',
    de: 'Kontaktanfrage',
    fr: 'Message de contact',
    ru: 'Контактное сообщение'
  },
  'contact.mailBody': {
    es: 'Hola Christian, me comunico de ...',
    en: 'Hi Christian, I am reaching out from ...',
    de: 'Hallo Christian, ich schreibe dir von ...',
    fr: 'Bonjour Christian, je vous contacte de la part de ...',
    ru: 'Здравствуйте, Кристиан. Я пишу вам от имени ...'
  },
  'contact.whatsappMessage': {
    es: 'Hola Christian, me comunico de ...',
    en: 'Hi Christian, I am reaching out from ...',
    de: 'Hallo Christian, ich schreibe dir von ...',
    fr: 'Bonjour Christian, je vous contacte de la part de ...',
    ru: 'Здравствуйте, Кристиан. Я пишу вам от имени ...'
  }
} satisfies Record<string, UiTextTranslations>;

const contentEntries: ContentTranslationEntry[] = [
  {
    es: 'Detección de leucemia con Python',
    en: 'Leukemia detection with Python',
    de: 'Leukämie-Erkennung mit Python',
    fr: 'Détection de leucémie avec Python',
    ru: 'Обнаружение лейкемии с помощью Python'
  },
  {
    es: 'Modelo de deep learning que es capaz de detectar cuatro etapas diferentes de leucemia. Implementado con Sklearn, Keras, NumPy y OpenCV.',
    en: 'Deep learning model capable of detecting four different stages of leukemia. Built with Sklearn, Keras, NumPy, and OpenCV.',
    de: 'Deep-Learning-Modell, das vier verschiedene Stadien von Leukämie erkennen kann. Implementiert mit Sklearn, Keras, NumPy und OpenCV.',
    fr: 'Modèle de deep learning capable de détecter quatre stades différents de leucémie. Réalisé avec Sklearn, Keras, NumPy et OpenCV.',
    ru: 'Модель глубокого обучения, способная определять четыре разные стадии лейкемии. Реализована с использованием Sklearn, Keras, NumPy и OpenCV.'
  },
  {
    es: 'Reconocimiento facial con Python',
    en: 'Face recognition with Python',
    de: 'Gesichtserkennung mit Python',
    fr: 'Reconnaissance faciale avec Python',
    ru: 'Распознавание лиц с помощью Python'
  },
  {
    es: 'Modelo de reconocimiento facial en Python implementado con NumPy, Tensorflow, FaceNet (de Keras) y MobileNet.',
    en: 'Face recognition model in Python built with NumPy, TensorFlow, FaceNet (from Keras), and MobileNet.',
    de: 'Gesichtserkennungsmodell in Python, implementiert mit NumPy, TensorFlow, FaceNet (aus Keras) und MobileNet.',
    fr: 'Modèle de reconnaissance faciale en Python réalisé avec NumPy, TensorFlow, FaceNet (de Keras) et MobileNet.',
    ru: 'Модель распознавания лиц на Python, реализованная с помощью NumPy, TensorFlow, FaceNet (из Keras) и MobileNet.'
  },
  {
    es: 'Detección de incendios forestales con Python',
    en: 'Wildfire detection with Python',
    de: 'Erkennung von Waldbränden mit Python',
    fr: 'Détection des incendies de forêt avec Python',
    ru: 'Обнаружение лесных пожаров с помощью Python'
  },
  {
    es: 'Modelo de deep learning que es capaz de detectar si hay fuego o no en imágenes de bosques. Implementado con Sklearn, Keras, NumPy y OpenCV.',
    en: 'Deep learning model capable of detecting whether there is fire in forest images. Built with Sklearn, Keras, NumPy, and OpenCV.',
    de: 'Deep-Learning-Modell, das in Waldaufnahmen erkennen kann, ob Feuer vorhanden ist oder nicht. Implementiert mit Sklearn, Keras, NumPy und OpenCV.',
    fr: 'Modèle de deep learning capable de détecter la présence de feu sur des images de forêt. Réalisé avec Sklearn, Keras, NumPy et OpenCV.',
    ru: 'Модель глубокого обучения, способная определять наличие огня на изображениях леса. Реализована с использованием Sklearn, Keras, NumPy и OpenCV.'
  },
  {
    es: 'Editor de texto con C#',
    en: 'Text editor with C#',
    de: 'Texteditor mit C#',
    fr: 'Éditeur de texte en C#',
    ru: 'Текстовый редактор на C#'
  },
  {
    es: 'Aplicación de escritorio para Windows +10, que permite editar texto de forma similar a Microsoft Word.',
    en: 'Desktop application for Windows 10+ that allows text editing in a way similar to Microsoft Word.',
    de: 'Desktop-Anwendung für Windows 10+, mit der Texte ähnlich wie in Microsoft Word bearbeitet werden können.',
    fr: 'Application de bureau pour Windows 10+ permettant de modifier du texte de façon similaire à Microsoft Word.',
    ru: 'Настольное приложение для Windows 10+, позволяющее редактировать текст примерно так же, как в Microsoft Word.'
  },
  {
    es: 'Acerca de (Versión de Vue.js)',
    en: 'About this project (Vue.js version)',
    de: 'Über dieses Projekt (Vue.js-Version)',
    fr: 'À propos de ce projet (version Vue.js)',
    ru: 'Об этом проекте (версия на Vue.js)'
  },
  {
    es: '¿Cómo fue creada esta interfaz web? (base de datos Supabase, hosting en GitHub Pages, y front-end con framework Vue.js)',
    en: 'How was this web interface built? (Supabase database, GitHub Pages hosting, and a Vue.js front end)',
    de: 'Wie wurde diese Weboberfläche erstellt? (Supabase-Datenbank, Hosting auf GitHub Pages und Frontend mit Vue.js)',
    fr: 'Comment cette interface web a-t-elle été créée ? (base de données Supabase, hébergement sur GitHub Pages et front-end avec Vue.js)',
    ru: 'Как была создана эта веб-интерфейс? (база данных Supabase, хостинг на GitHub Pages и фронтенд на Vue.js)'
  },
  {
    es: 'Análisis de vulnerabilidades a través del sistema operativo Alma Linux',
    en: 'Vulnerability analysis through the Alma Linux operating system',
    de: 'Schwachstellenanalyse mit dem Betriebssystem Alma Linux',
    fr: "Analyse de vulnérabilités à travers le système d'exploitation Alma Linux",
    ru: 'Анализ уязвимостей с использованием операционной системы Alma Linux'
  },
  {
    es: 'Proyecto de investigación junior: documentar el uso de cinco herramientas de ciberseguridad en Alma Linux.',
    en: 'Junior research project: documenting the use of five cybersecurity tools in Alma Linux.',
    de: 'Junior-Forschungsprojekt: Dokumentation des Einsatzes von fünf Cybersicherheitswerkzeugen unter Alma Linux.',
    fr: "Projet de recherche junior : documenter l'utilisation de cinq outils de cybersécurité sous Alma Linux.",
    ru: 'Исследовательский junior-проект: документирование использования пяти инструментов кибербезопасности в Alma Linux.'
  },
  {
    es: 'Ontología BUAP FCC con Protegé',
    en: 'BUAP FCC ontology with Protégé',
    de: 'BUAP-FCC-Ontologie mit Protégé',
    fr: 'Ontologie BUAP FCC avec Protégé',
    ru: 'Онтология BUAP FCC в Protégé'
  },
  {
    es: 'Modelado de diversas entidades a través de datos XML, RDF, Turtle, OWL, etc. Mediante el software "Protegé".',
    en: 'Modeling different entities through XML, RDF, Turtle, OWL, and related data using the Protégé software.',
    de: 'Modellierung verschiedener Entitäten mithilfe von XML-, RDF-, Turtle-, OWL- und ähnlichen Daten mit der Software Protégé.',
    fr: 'Modélisation de différentes entités à partir de données XML, RDF, Turtle, OWL, etc., à l’aide du logiciel Protégé.',
    ru: 'Моделирование различных сущностей с помощью данных XML, RDF, Turtle, OWL и других форматов в программном обеспечении Protégé.'
  },
  {
    es: 'Reporte de servicio social',
    en: 'Social service report',
    de: 'Bericht zum Sozialdienst',
    fr: 'Rapport de service social',
    ru: 'Отчет о социальной практике'
  },
  {
    es: 'Reporte final que entregué a mi facultad al concluír mi servicio social universitario.',
    en: 'Final report that I submitted to my faculty after completing my university social service.',
    de: 'Abschlussbericht, den ich meiner Fakultät nach Beendigung meines universitären Sozialdienstes eingereicht habe.',
    fr: "Rapport final que j'ai remis à ma faculté à la fin de mon service social universitaire.",
    ru: 'Итоговый отчет, который я передал факультету после завершения своей университетской социальной практики.'
  },
  {
    es: 'Cursos de mi autoría',
    en: 'Courses authored by me',
    de: 'Von mir erstellte Kurse',
    fr: 'Cours conçus par moi',
    ru: 'Курсы моего авторства'
  },
  {
    es: 'Temario y scripts que escribí para dar clases a estudiantes universitarios y desarrolladores. (POO en C++ y en Java, Estructuras de Datos, y ejercicios de Programación 1).',
    en: 'Syllabi and scripts that I wrote to teach university students and developers. (OOP in C++ and Java, Data Structures, and Programming 1 exercises).',
    de: 'Lehrpläne und Skripte, die ich geschrieben habe, um Universitätsstudierende und Entwickler zu unterrichten. (OOP in C++ und Java, Datenstrukturen und Übungen aus Programmierung 1).',
    fr: "Supports de cours et scripts que j'ai rédigés pour enseigner à des étudiants universitaires et à des développeurs. (POO en C++ et en Java, structures de données et exercices de programmation 1).",
    ru: 'Учебные программы и скрипты, которые я написал для занятий со студентами и разработчиками. (ООП на C++ и Java, структуры данных и упражнения по программированию 1).'
  },
  {
    es: 'Notas de licenciatura',
    en: "Bachelor's degree notes",
    de: 'Notizen aus dem Bachelorstudium',
    fr: 'Notes de licence',
    ru: 'Материалы бакалавриата'
  },
  {
    es: 'Recopilación de prácticas, proyectos, apuntes y borradores de distintas áreas de formación de licenciatura (hilos y procesos, algoritmos, circuitos, graficación, virtualización, servidores, etc.)',
    en: "Collection of assignments, projects, notes, and drafts from different areas of my bachelor's degree training (threads and processes, algorithms, circuits, computer graphics, virtualization, servers, etc.).",
    de: 'Sammlung von Übungen, Projekten, Notizen und Entwürfen aus verschiedenen Bereichen meines Bachelorstudiums (Threads und Prozesse, Algorithmen, Schaltungen, Computergrafik, Virtualisierung, Server usw.).',
    fr: 'Recueil de travaux pratiques, projets, notes et brouillons issus de différentes matières de licence (threads et processus, algorithmes, circuits, infographie, virtualisation, serveurs, etc.).',
    ru: 'Сборник практик, проектов, заметок и черновиков из разных областей бакалавриата (потоки и процессы, алгоритмы, схемы, графика, виртуализация, серверы и т.д.).'
  },
  {
    es: 'Prototipo de administrador de tareas con C++',
    en: 'Task manager prototype with C++',
    de: 'Prototyp eines Task-Managers mit C++',
    fr: 'Prototype de gestionnaire de tâches en C++',
    ru: 'Прототип диспетчера задач на C++'
  },
  {
    es: 'Proyecto final de la materia de Sistemas Operativos 1: Script que trabaja dieciséis modos de operación para gestionar tareas.',
    en: 'Final project for the Operating Systems 1 course: a script with sixteen operating modes for task management.',
    de: 'Abschlussprojekt des Fachs Betriebssysteme 1: Ein Skript mit sechzehn Betriebsmodi zur Aufgabenverwaltung.',
    fr: "Projet final du cours Systèmes d'exploitation 1 : script utilisant seize modes de fonctionnement pour gérer des tâches.",
    ru: 'Итоговый проект по дисциплине «Операционные системы 1»: скрипт с шестнадцатью режимами работы для управления задачами.'
  },
  {
    es: 'Aplicación para Windows, que interactúa con el fondo de escritorio.',
    en: 'Windows application that interacts with the desktop wallpaper.',
    de: 'Windows-Anwendung, die mit dem Desktop-Hintergrund interagiert.',
    fr: 'Application Windows qui interagit avec le fond d’écran.',
    ru: 'Приложение для Windows, которое взаимодействует с фоном рабочего стола.'
  },
  {
    es: 'Mini-proyecto Python personal, que toma algunos recursos técnicos de Windows para automatizar una función multimedia.',
    en: 'Personal Python mini-project that uses some Windows technical resources to automate a multimedia function.',
    de: 'Persönliches Python-Miniprojekt, das einige technische Windows-Ressourcen nutzt, um eine Multimediafunktion zu automatisieren.',
    fr: 'Mini-projet personnel en Python qui exploite certaines ressources techniques de Windows pour automatiser une fonction multimédia.',
    ru: 'Личный мини-проект на Python, использующий некоторые технические возможности Windows для автоматизации мультимедийной функции.'
  },
  {
    es: 'Automatización de procesos en control de producción y desarrollo de aplicación predictiva para gestión de mantenimiento - Audi',
    en: 'Process automation in production control and predictive application development for maintenance management - Audi',
    de: 'Prozessautomatisierung in der Produktionssteuerung und Entwicklung einer prädiktiven Anwendung für das Instandhaltungsmanagement - Audi',
    fr: 'Automatisation des processus en contrôle de production et développement d’une application prédictive pour la gestion de maintenance - Audi',
    ru: 'Автоматизация процессов в производственном контроле и разработка предиктивного приложения для управления техническим обслуживанием - Audi'
  },
  {
    es: 'Diseño, desarrollo e implementación de un sistema de software especializado para el área de mantenimiento de carrocerías, con el objetivo de optimizar la gestión técnica de las tecnologías utilizadas en la fabricación de carrocerías || Automatización de procesos y reportes en el área de control de producción',
    en: 'Design, development, and implementation of a specialized software system for the body maintenance area, aimed at optimizing the technical management of the technologies used in body manufacturing || Process and reporting automation in the production control area',
    de: 'Entwurf, Entwicklung und Implementierung eines spezialisierten Softwaresystems für den Karosserie-Instandhaltungsbereich mit dem Ziel, das technische Management der in der Karosseriefertigung eingesetzten Technologien zu optimieren || Automatisierung von Prozessen und Berichten im Bereich Produktionssteuerung',
    fr: "Conception, développement et mise en œuvre d'un système logiciel spécialisé pour le domaine de la maintenance des carrosseries, afin d’optimiser la gestion technique des technologies utilisées dans leur fabrication || Automatisation des processus et des rapports dans le domaine du contrôle de production",
    ru: 'Проектирование, разработка и внедрение специализированной программной системы для подразделения обслуживания кузовов с целью оптимизации технического управления технологиями, используемыми при производстве кузовов || Автоматизация процессов и отчетности в зоне производственного контроля'
  },
  {
    es: 'Desarrollo de software.',
    en: 'Software development.',
    de: 'Softwareentwicklung.',
    fr: 'Développement logiciel.',
    ru: 'Разработка программного обеспечения.'
  },
  {
    es: 'Levantamiento de requerimientos funcionales y técnicos junto al equipo de Planeación de Mantenimiento.',
    en: 'Gathering functional and technical requirements together with the Maintenance Planning team.',
    de: 'Erhebung funktionaler und technischer Anforderungen gemeinsam mit dem Team für Instandhaltungsplanung.',
    fr: "Recueil des exigences fonctionnelles et techniques avec l’équipe de planification de la maintenance.",
    ru: 'Сбор функциональных и технических требований вместе с командой планирования технического обслуживания.'
  },
  {
    es: 'Integración de módulos para el registro de mantenimientos, análisis de fallas y seguimiento de parámetros técnicos.',
    en: 'Module integration for maintenance records, failure analysis, and technical parameter tracking.',
    de: 'Integration von Modulen für Wartungsprotokolle, Fehleranalyse und Nachverfolgung technischer Parameter.',
    fr: "Intégration de modules pour l’enregistrement des maintenances, l’analyse des pannes et le suivi des paramètres techniques.",
    ru: 'Интеграция модулей для регистрации обслуживания, анализа отказов и отслеживания технических параметров.'
  },
  {
    es: 'Documentación técnica del sistema y capacitación básica a usuarios finales.',
    en: 'Technical system documentation and basic training for end users.',
    de: 'Technische Systemdokumentation und grundlegende Schulung für Endanwender.',
    fr: 'Documentation technique du système et formation de base pour les utilisateurs finaux.',
    ru: 'Техническая документация системы и базовое обучение конечных пользователей.'
  },
  {
    es: 'Propuesta de mejoras continuas con base en retroalimentación del equipo técnico.',
    en: 'Continuous improvement proposals based on feedback from the technical team.',
    de: 'Vorschläge für kontinuierliche Verbesserungen auf Grundlage des Feedbacks des technischen Teams.',
    fr: "Proposition d’améliorations continues à partir des retours de l’équipe technique.",
    ru: 'Предложения по непрерывным улучшениям на основе обратной связи от технической команды.'
  },
  {
    es: 'Diseño y creación de bases de datos, arquitectura de sistemas, interfaz de usuario, lógica de negocios, flujos de información, plantillas de ingreso de datos y dashboards.',
    en: 'Design and creation of databases, systems architecture, user interface, business logic, information flows, data entry templates, and dashboards.',
    de: 'Entwurf und Erstellung von Datenbanken, Systemarchitektur, Benutzeroberfläche, Geschäftslogik, Informationsflüssen, Dateneingabevorlagen und Dashboards.',
    fr: "Conception et création de bases de données, architecture système, interface utilisateur, logique métier, flux d’information, modèles de saisie et tableaux de bord.",
    ru: 'Проектирование и создание баз данных, архитектуры систем, пользовательского интерфейса, бизнес-логики, информационных потоков, шаблонов ввода данных и дашбордов.'
  },
  {
    es: 'Pruebas funcionales y validación del sistema con usuarios del área.',
    en: 'Functional testing and system validation with department users.',
    de: 'Funktionstests und Systemvalidierung mit Anwendern aus dem Fachbereich.',
    fr: "Tests fonctionnels et validation du système avec les utilisateurs du service.",
    ru: 'Функциональное тестирование и валидация системы вместе с пользователями подразделения.'
  },
  {
    es: 'Implementación de procesos adicionales a los establecidos en los requerimientos iniciales.',
    en: 'Implementation of additional processes beyond those defined in the initial requirements.',
    de: 'Implementierung zusätzlicher Prozesse über die ursprünglichen Anforderungen hinaus.',
    fr: "Mise en œuvre de processus supplémentaires au-delà des exigences initiales.",
    ru: 'Реализация дополнительных процессов сверх тех, что были определены в первоначальных требованиях.'
  },
  {
    es: 'Migración y reestructuración de sistemas previamente establecidos.',
    en: 'Migration and restructuring of previously established systems.',
    de: 'Migration und Umstrukturierung zuvor bestehender Systeme.',
    fr: 'Migration et restructuration de systèmes déjà en place.',
    ru: 'Миграция и реструктуризация ранее существовавших систем.'
  },
  {
    es: 'Soporte técnico (hardware y software) - Torre de Gestión Académica y Servicios Administrativos, BUAP.',
    en: 'Technical support (hardware and software) - Academic Management and Administrative Services Tower, BUAP.',
    de: 'Technischer Support (Hardware und Software) - Turm für Akademisches Management und Verwaltungsdienste, BUAP.',
    fr: 'Support technique (matériel et logiciel) - Tour de gestion académique et de services administratifs, BUAP.',
    ru: 'Техническая поддержка (оборудование и ПО) - Башня академического управления и административных услуг, BUAP.'
  },
  {
    es: 'Para acreditar mi servicio social, solicité la creación de un programa que me permitiera ofrecer soporte técnico tanto en hardware como en software a los equipos de cómputo y servidores del tercer piso de la torre (Dirección de Servicio Social) (reporte disponible en la sección "portafolio").',
    en: 'To complete my social service requirement, I requested the creation of a program that would allow me to provide hardware and software technical support to the computers and servers on the third floor of the tower (Social Service Office) (report available in the portfolio section).',
    de: 'Zur Anerkennung meines Sozialdienstes beantragte ich die Einrichtung eines Programms, das es mir ermöglichte, den Computern und Servern im dritten Stock des Turms (Abteilung Sozialdienst) technischen Support für Hardware und Software zu leisten (Bericht im Bereich "Portfolio" verfügbar).',
    fr: "Pour valider mon service social, j’ai demandé la création d’un programme me permettant d’offrir un support technique matériel et logiciel aux ordinateurs et serveurs du troisième étage de la tour (Direction du service social) (rapport disponible dans la section portfolio).",
    ru: 'Для зачета социальной практики я инициировал создание программы, которая позволила бы мне оказывать техническую поддержку по аппаратной и программной части компьютерам и серверам на третьем этаже башни (Управление социальной практики) (отчет доступен в разделе портфолио).'
  },
  {
    es: 'Mantenimiento preventivo del hardware.',
    en: 'Preventive hardware maintenance.',
    de: 'Präventive Wartung der Hardware.',
    fr: 'Maintenance préventive du matériel.',
    ru: 'Профилактическое обслуживание оборудования.'
  },
  {
    es: 'Instalación y administración de sistemas operativos (Windows 10 y 11, Windows Server, Windows Sergei).',
    en: 'Installation and administration of operating systems (Windows 10 and 11, Windows Server, Windows Sergei).',
    de: 'Installation und Verwaltung von Betriebssystemen (Windows 10 und 11, Windows Server, Windows Sergei).',
    fr: "Installation et administration de systèmes d’exploitation (Windows 10 et 11, Windows Server, Windows Sergei).",
    ru: 'Установка и администрирование операционных систем (Windows 10 и 11, Windows Server, Windows Sergei).'
  },
  {
    es: 'Creación y administración de respaldos de datos pertenecientes al personal del piso.',
    en: 'Creation and administration of data backups for the staff on that floor.',
    de: 'Erstellung und Verwaltung von Datensicherungen für das Personal dieser Etage.',
    fr: 'Création et gestion des sauvegardes de données du personnel de cet étage.',
    ru: 'Создание и администрирование резервных копий данных сотрудников этого этажа.'
  },
  {
    es: 'Soporte a las dudas del personal del piso, sobre temas técnicos del software o hardware de la oficina (Microsoft Office, uso de impresoras, problemas de red, etc.).',
    en: 'Support for the staff’s questions about office software and hardware technical issues (Microsoft Office, printer usage, network problems, etc.).',
    de: 'Unterstützung bei Fragen des Personals zu technischen Themen rund um Software und Hardware im Büro (Microsoft Office, Druckernutzung, Netzwerkprobleme usw.).',
    fr: "Assistance aux questions du personnel concernant les sujets techniques liés aux logiciels ou au matériel du bureau (Microsoft Office, imprimantes, problèmes réseau, etc.).",
    ru: 'Поддержка сотрудников по техническим вопросам, связанным с программным и аппаратным обеспечением офиса (Microsoft Office, использование принтеров, сетевые проблемы и т. д.).'
  },
  {
    es: 'Capacitación de emergencia del personal para uso de software y hardware para eventos online. (Junto a la pronta configuración de las tecnologías usadas).',
    en: 'Emergency staff training on software and hardware for online events, along with rapid configuration of the technologies used.',
    de: 'Notfallschulung des Personals für den Einsatz von Software und Hardware bei Online-Veranstaltungen sowie schnelle Konfiguration der verwendeten Technologien.',
    fr: "Formation d’urgence du personnel à l’utilisation de logiciels et de matériel pour des événements en ligne, ainsi que configuration rapide des technologies utilisées.",
    ru: 'Экстренное обучение персонала использованию программного и аппаратного обеспечения для онлайн-мероприятий вместе с оперативной настройкой применяемых технологий.'
  },
  {
    es: 'Consultas y asesorías - Independiente.',
    en: 'Consulting and tutoring - Independent.',
    de: 'Beratung und Nachhilfe - Selbstständig.',
    fr: 'Consultations et accompagnement - Indépendant.',
    ru: 'Консультации и сопровождение - частная практика.'
  },
  {
    es: 'Desde una etapa temprana de mi licenciatura, algunas personas (desarrolladores y alumnos universitarios) me empezaron a solicitar asesorías y consultas (o directamente trabajos completos) en diversos tópicos relacionados con desarrollo de software. Y siempre que tuve la oportunidad de brindar uno de esos servicios, lo hice.',
    en: 'From an early stage of my degree, some people (developers and university students) started asking me for tutoring and consulting services, or even complete deliverables, on different software development topics. Whenever I had the opportunity to provide one of those services, I did.',
    de: 'Schon früh in meinem Studium begannen mich einige Personen (Entwickler und Studierende) um Beratung, Nachhilfe oder sogar komplette Arbeiten zu verschiedenen Themen der Softwareentwicklung zu bitten. Und wann immer ich die Gelegenheit hatte, eine dieser Leistungen anzubieten, habe ich es getan.',
    fr: "Dès les premières étapes de ma licence, certaines personnes (développeurs et étudiants universitaires) ont commencé à me demander des conseils, de l’accompagnement ou même des travaux complets sur différents sujets liés au développement logiciel. Et chaque fois que j’ai eu l’occasion de fournir l’un de ces services, je l’ai fait.",
    ru: 'С ранних этапов обучения некоторые люди (разработчики и студенты) начали обращаться ко мне за консультациями, наставничеством или даже за полностью выполненными работами по разным темам разработки ПО. И всякий раз, когда у меня была возможность оказать такую услугу, я это делал.'
  },
  {
    es: 'Consultas personalizadas.',
    en: 'Personalized consulting.',
    de: 'Personalisierte Beratung.',
    fr: 'Conseils personnalisés.',
    ru: 'Персональные консультации.'
  },
  {
    es: 'Modificación de scripts previamente escritos (y garantizar el funcionamiento de los mismos).',
    en: 'Modification of previously written scripts and ensuring that they work properly.',
    de: 'Anpassung bereits geschriebener Skripte und Sicherstellung ihrer Funktionsfähigkeit.',
    fr: 'Modification de scripts déjà écrits et garantie de leur bon fonctionnement.',
    ru: 'Модификация ранее написанных скриптов и обеспечение их корректной работы.'
  },
  {
    es: 'Satisfacción reflejada en cada testimonio recibido.',
    en: 'Satisfaction reflected in every testimonial received.',
    de: 'Zufriedenheit, die sich in jedem erhaltenen Erfahrungsbericht widerspiegelt.',
    fr: 'Satisfaction reflétée dans chaque témoignage reçu.',
    ru: 'Удовлетворенность, отраженная в каждом полученном отзыве.'
  },
  {
    es: 'Reconocimiento y recomendación recurrentes.',
    en: 'Repeated recognition and recommendations.',
    de: 'Wiederkehrende Anerkennung und Empfehlungen.',
    fr: 'Reconnaissance et recommandations récurrentes.',
    ru: 'Постоянное признание и рекомендации.'
  },
  {
    es: 'Ingeniería en Ciencias de la Computación - Benemérita Universidad Autónoma de Puebla',
    en: 'Computer Science Engineering - Meritorious Autonomous University of Puebla',
    de: 'Ingenieurwesen der Informatik - Benemérita Universidad Autónoma de Puebla',
    fr: 'Ingénierie en informatique - Benemérita Universidad Autónoma de Puebla',
    ru: 'Инженерия в области компьютерных наук - Benemérita Universidad Autónoma de Puebla'
  },
  {
    es: 'Ingeniería de cincuenta materias que incluyen desde las bases elementales de la computación, como metodología de la programación, circuitos eléctricos, ensamblador y diseño digital, hasta tecnologías prácticas como bases de datos, diseño web, web semántica, deep learning, entre otras. Tanto la BUAP como su Facultad de Ciencias de la Computación han sido reconocidas nacional e internacionalmente por su aprovechamiento académico y el talento de sus egresados.',
    en: 'Engineering degree with fifty courses covering everything from the elementary foundations of computing, such as programming methodology, electrical circuits, assembly language, and digital design, to practical technologies like databases, web design, semantic web, deep learning, and more. Both BUAP and its Computer Science Faculty have been recognized nationally and internationally for academic excellence and the talent of their graduates.',
    de: 'Ingenieurstudium mit fünfzig Fächern, die von den grundlegenden Basen der Informatik wie Programmiermethodik, elektrische Schaltungen, Assembler und digitales Design bis hin zu praktischen Technologien wie Datenbanken, Webdesign, semantischem Web und Deep Learning reichen. Sowohl die BUAP als auch ihre Fakultät für Informatik wurden national und international für ihre akademische Qualität und die Begabung ihrer Absolventen anerkannt.',
    fr: "Diplôme d’ingénierie composé de cinquante matières couvrant les bases élémentaires de l’informatique, comme la méthodologie de programmation, les circuits électriques, l’assembleur et la conception numérique, jusqu’à des technologies pratiques telles que les bases de données, le design web, le web sémantique, le deep learning, entre autres. La BUAP et sa faculté d’informatique ont été reconnues au niveau national et international pour leur excellence académique et le talent de leurs diplômés.",
    ru: 'Инженерная программа из пятидесяти дисциплин, охватывающих как базовые основы вычислительной техники, такие как методология программирования, электрические схемы, ассемблер и цифровой дизайн, так и прикладные технологии, включая базы данных, веб-дизайн, семантический веб, deep learning и многое другое. И BUAP, и ее факультет компьютерных наук получили национальное и международное признание за академические результаты и талант своих выпускников.'
  },
  {
    es: '🎓 LICENCIATURA',
    en: "🎓 BACHELOR'S DEGREE",
    de: '🎓 BACHELORSTUDIUM',
    fr: '🎓 LICENCE',
    ru: '🎓 БАКАЛАВРИАТ'
  },
  {
    es: 'Programa de formación gratuito que abarca más de 700 horas de contenido, estructurado en dos etapas: fundamentos de programación, bases de datos y especialización en áreas como Ciencia de Datos, Inteligencia Artificial, Back-End y Oracle Cloud. Está orientado a preparar profesionales con habilidades prácticas altamente demandadas en la industria.',
    en: 'Free training program with more than 700 hours of content, structured in two stages: programming fundamentals, databases, and specialization in areas such as Data Science, Artificial Intelligence, Back-End, and Oracle Cloud. It is designed to prepare professionals with practical skills that are highly demanded in the industry.',
    de: 'Kostenloses Ausbildungsprogramm mit mehr als 700 Stunden Inhalt, strukturiert in zwei Phasen: Programmiergrundlagen, Datenbanken und Spezialisierung in Bereichen wie Data Science, Künstliche Intelligenz, Back-End und Oracle Cloud. Es soll Fachkräfte mit praxisnahen, in der Industrie stark nachgefragten Fähigkeiten ausbilden.',
    fr: 'Programme de formation gratuit de plus de 700 heures, structuré en deux étapes : fondamentaux de la programmation, bases de données et spécialisation dans des domaines comme la Data Science, l’Intelligence Artificielle, le Back-End et Oracle Cloud. Il vise à former des professionnels dotés de compétences pratiques très recherchées dans l’industrie.',
    ru: 'Бесплатная образовательная программа объемом более 700 часов, разделенная на два этапа: основы программирования, базы данных и специализация в таких областях, как Data Science, искусственный интеллект, back-end и Oracle Cloud. Программа ориентирована на подготовку специалистов с практическими навыками, востребованными в индустрии.'
  },
  {
    es: '📅 BOOTCAMP',
    en: '📅 BOOTCAMP',
    de: '📅 BOOTCAMP',
    fr: '📅 BOOTCAMP',
    ru: '📅 БУТКЕМП'
  },
  {
    es: 'Deep Learning con Python - SciData',
    en: 'Deep Learning with Python - SciData',
    de: 'Deep Learning mit Python - SciData',
    fr: 'Deep Learning avec Python - SciData',
    ru: 'Deep Learning с Python - SciData'
  },
  {
    es: 'Programa enfocado en el aprendizaje profundo con Python, abarcando perceptrones multicapa, Stochastic Gradient Descent (SGD) y la implementación manual de propagación hacia adelante y hacia atrás. Se utiliza Keras para construir modelos, junto con validación cruzada y optimización de hiperparámetros. Se cubren técnicas de regularización, como L1, L2, Dropout y Batch normalization, para evitar underfitting y overfitting. Además, incluye redes neuronales convolucionales (CNN) y recurrentes (RNN).',
    en: 'Program focused on deep learning with Python, covering multilayer perceptrons, Stochastic Gradient Descent (SGD), and manual implementation of forward and backward propagation. Keras is used to build models, together with cross-validation and hyperparameter optimization. Regularization techniques such as L1, L2, Dropout, and Batch Normalization are covered to avoid underfitting and overfitting. It also includes convolutional neural networks (CNNs) and recurrent neural networks (RNNs).',
    de: 'Programm mit Schwerpunkt Deep Learning in Python, einschließlich mehrschichtiger Perzeptrons, Stochastic Gradient Descent (SGD) sowie manueller Implementierung von Vorwärts- und Rückwärtspropagation. Keras wird zum Aufbau von Modellen verwendet, zusammen mit Kreuzvalidierung und Hyperparameter-Optimierung. Es werden Regularisierungstechniken wie L1, L2, Dropout und Batch-Normalisierung behandelt, um Underfitting und Overfitting zu vermeiden. Außerdem umfasst es konvolutionale neuronale Netze (CNNs) und rekurrente neuronale Netze (RNNs).',
    fr: 'Programme axé sur le deep learning avec Python, couvrant les perceptrons multicouches, le Stochastic Gradient Descent (SGD) et la mise en œuvre manuelle de la propagation avant et arrière. Keras est utilisé pour construire les modèles, avec validation croisée et optimisation des hyperparamètres. Des techniques de régularisation comme L1, L2, Dropout et Batch Normalization sont également abordées afin d’éviter le sous-apprentissage et le surapprentissage. Le programme inclut aussi les réseaux neuronaux convolutifs (CNN) et récurrents (RNN).',
    ru: 'Программа по глубокому обучению на Python, охватывающая многослойные перцептроны, Stochastic Gradient Descent (SGD) и ручную реализацию прямого и обратного распространения. Для построения моделей используется Keras вместе с кросс-валидацией и оптимизацией гиперпараметров. Рассматриваются методы регуляризации, такие как L1, L2, Dropout и Batch Normalization, чтобы избегать недообучения и переобучения. Также в программу входят сверточные (CNN) и рекуррентные (RNN) нейронные сети.'
  },
  {
    es: '📚 CURSO',
    en: '📚 COURSE',
    de: '📚 KURS',
    fr: '📚 COURS',
    ru: '📚 КУРС'
  },
  {
    es: 'Diseño y administración de bases de datos con SQL - SciData',
    en: 'Database design and administration with SQL - SciData',
    de: 'Entwurf und Verwaltung von Datenbanken mit SQL - SciData',
    fr: 'Conception et administration de bases de données avec SQL - SciData',
    ru: 'Проектирование и администрирование баз данных с SQL - SciData'
  },
  {
    es: 'Curso enfocado en los aspectos teóricos del diseño de bases de datos (como modelado con diagramas entidad-relación, normalización, álgebra relacional, diseño de consultas, etc.), llevados a la práctica con PostgreSQL y sus características específicas (como su interfaz gráfica, sus opciones de configuración y seguridad, etc).',
    en: 'Course focused on the theoretical aspects of database design (such as entity-relationship modeling, normalization, relational algebra, query design, etc.), put into practice with PostgreSQL and its specific features (such as its graphical interface, configuration options, security settings, etc.).',
    de: 'Kurs mit Schwerpunkt auf den theoretischen Aspekten des Datenbankdesigns (wie Entity-Relationship-Modellierung, Normalisierung, relationale Algebra, Abfrageentwurf usw.), die mit PostgreSQL und seinen spezifischen Funktionen (grafische Oberfläche, Konfigurations- und Sicherheitsoptionen usw.) in die Praxis umgesetzt werden.',
    fr: 'Cours axé sur les aspects théoriques de la conception de bases de données (modélisation entité-relation, normalisation, algèbre relationnelle, conception de requêtes, etc.), mis en pratique avec PostgreSQL et ses fonctionnalités spécifiques (interface graphique, options de configuration et de sécurité, etc.).',
    ru: 'Курс, посвященный теоретическим аспектам проектирования баз данных (моделирование сущность-связь, нормализация, реляционная алгебра, проектирование запросов и т.д.), применяемым на практике с PostgreSQL и его особенностями (графический интерфейс, параметры конфигурации и безопасности и т.д.).'
  },
  {
    es: 'Probabilidad con R - SciData',
    en: 'Probability with R - SciData',
    de: 'Wahrscheinlichkeit mit R - SciData',
    fr: 'Probabilités avec R - SciData',
    ru: 'Теория вероятностей с R - SciData'
  },
  {
    es: 'Curso brindado por un científico de datos con experiencia, enfocado en los fundamentos teóricos de la probabilidad, llevados a la práctica en el lenguaje R.',
    en: 'Course taught by an experienced data scientist, focused on the theoretical foundations of probability and their practical application in the R language.',
    de: 'Kurs eines erfahrenen Data Scientists mit Schwerpunkt auf den theoretischen Grundlagen der Wahrscheinlichkeitsrechnung und ihrer praktischen Anwendung in der Programmiersprache R.',
    fr: 'Cours donné par un data scientist expérimenté, axé sur les fondements théoriques des probabilités et leur mise en pratique avec le langage R.',
    ru: 'Курс, проведенный опытным специалистом по данным, посвященный теоретическим основам вероятности и их практическому применению в языке R.'
  },
  {
    es: 'Excel avanzado con Visual Basic (programación en Excel) - SciData',
    en: 'Advanced Excel with Visual Basic (Excel programming) - SciData',
    de: 'Fortgeschrittenes Excel mit Visual Basic (Programmierung in Excel) - SciData',
    fr: 'Excel avancé avec Visual Basic (programmation dans Excel) - SciData',
    ru: 'Продвинутый Excel с Visual Basic (программирование в Excel) - SciData'
  },
  {
    es: 'Taller de ocho horas de duración en el que se llevan a cabo tres trabajos con Visual Basic para automatizar y estilizar algunas operaciones de Excel (como inserción, creación, modificación, eliminación, etc.).',
    en: 'Eight-hour workshop in which three Visual Basic exercises are carried out to automate and style several Excel operations (such as insertion, creation, modification, deletion, etc.).',
    de: 'Achtstündiger Workshop, in dem drei Arbeiten mit Visual Basic durchgeführt werden, um verschiedene Excel-Operationen (Einfügen, Erstellen, Ändern, Löschen usw.) zu automatisieren und zu gestalten.',
    fr: "Atelier de huit heures au cours duquel trois travaux en Visual Basic sont réalisés afin d’automatiser et de styliser certaines opérations dans Excel (insertion, création, modification, suppression, etc.).",
    ru: 'Восьмичасовой практикум, в рамках которого выполняются три работы на Visual Basic для автоматизации и оформления некоторых операций Excel (вставка, создание, изменение, удаление и т.д.).'
  },
  {
    es: 'CONACIC 2021: III Congreso Internacional, XI Congreso Nacional de Ciencias de La Computación',
    en: 'CONACIC 2021: 3rd International Congress, 11th National Congress of Computer Science',
    de: 'CONACIC 2021: III. Internationaler Kongress, XI. Nationaler Kongress für Informatik',
    fr: "CONACIC 2021 : IIIe Congrès international, XIe Congrès national des sciences informatiques",
    ru: 'CONACIC 2021: III Международный конгресс, XI Национальный конгресс по компьютерным наукам'
  },
  {
    es: 'Congreso académico que abordó temas como inteligencia artificial, ciberseguridad, robótica y ciencia de datos. Organizado por la BUAP, incluyó conferencias, talleres y presentaciones de trabajos publicados en la revista Research in Computing Science. Los talleres a los que asistí fueron los siguientes: Introducción a las Redes de Computadoras (6 horas), Arquitecturas Defensivas Dinámicas (6 horas), Realidad Aumentada en la Palma de tu Mano (6 horas) y 3D desde cero con Open Source (6 horas).',
    en: 'Academic congress that addressed topics such as artificial intelligence, cybersecurity, robotics, and data science. Organized by BUAP, it included conferences, workshops, and presentations of papers published in the journal Research in Computing Science. The workshops I attended were: Introduction to Computer Networks (6 hours), Dynamic Defensive Architectures (6 hours), Augmented Reality in the Palm of Your Hand (6 hours), and 3D from Scratch with Open Source (6 hours).',
    de: 'Akademischer Kongress zu Themen wie künstliche Intelligenz, Cybersicherheit, Robotik und Data Science. Organisiert von der BUAP, umfasste er Vorträge, Workshops und Präsentationen von in der Zeitschrift Research in Computing Science veröffentlichten Arbeiten. Die von mir besuchten Workshops waren: Einführung in Computernetzwerke (6 Stunden), Dynamische defensive Architekturen (6 Stunden), Augmented Reality in deiner Handfläche (6 Stunden) und 3D von Grund auf mit Open Source (6 Stunden).',
    fr: "Congrès académique abordant des thèmes tels que l’intelligence artificielle, la cybersécurité, la robotique et la science des données. Organisé par la BUAP, il comprenait des conférences, des ateliers et des présentations de travaux publiés dans la revue Research in Computing Science. Les ateliers auxquels j’ai assisté étaient : Introduction aux réseaux informatiques (6 heures), Architectures défensives dynamiques (6 heures), Réalité augmentée dans la paume de la main (6 heures) et 3D depuis zéro avec l’open source (6 heures).",
    ru: 'Академический конгресс, посвященный таким темам, как искусственный интеллект, кибербезопасность, робототехника и наука о данных. Организованный BUAP, он включал конференции, мастер-классы и презентации работ, опубликованных в журнале Research in Computing Science. Я посетил следующие мастер-классы: Введение в компьютерные сети (6 часов), Динамические защитные архитектуры (6 часов), Дополненная реальность на ладони (6 часов) и 3D с нуля с Open Source (6 часов).'
  },
  {
    es: '🏛️ CONGRESO',
    en: '🏛️ CONGRESS',
    de: '🏛️ KONGRESS',
    fr: '🏛️ CONGRÈS',
    ru: '🏛️ КОНГРЕСС'
  },
  {
    es: 'Introducción a Ciencia de Datos con RStudio - SciData',
    en: 'Introduction to Data Science with RStudio - SciData',
    de: 'Einführung in Data Science mit RStudio - SciData',
    fr: 'Introduction à la science des données avec RStudio - SciData',
    ru: 'Введение в Data Science с RStudio - SciData'
  },
  {
    es: 'Taller de una sesión que introduce al alumno a los principios teóricos de ciencias de datos usando RStudio para los aspectos prácticos, particularmente explorando sobre datos reales de COVID 19 en México.',
    en: 'Single-session workshop that introduces students to the theoretical principles of data science using RStudio for the practical part, especially through real COVID-19 data from Mexico.',
    de: 'Eintägiger Workshop, der Studierende in die theoretischen Grundlagen der Data Science einführt und RStudio für den praktischen Teil nutzt, insbesondere anhand realer COVID-19-Daten aus Mexiko.',
    fr: "Atelier d’une seule session qui initie l’étudiant aux principes théoriques de la science des données en utilisant RStudio pour la partie pratique, notamment à partir de données réelles sur le COVID-19 au Mexique.",
    ru: 'Односессионный практикум, знакомящий студентов с теоретическими принципами Data Science и использующий RStudio для практической части, в частности на реальных данных по COVID-19 в Мексике.'
  },
  {
    es: '🛠️ TALLER',
    en: '🛠️ WORKSHOP',
    de: '🛠️ WORKSHOP',
    fr: '🛠️ ATELIER',
    ru: '🛠️ МАСТЕР-КЛАСС'
  },
  {
    es: 'Programación para Android desde cero con Java +40 horas - Jose Javier Villena',
    en: 'Android programming from scratch with Java +40 hours - Jose Javier Villena',
    de: 'Android-Programmierung von Grund auf mit Java +40 Stunden - Jose Javier Villena',
    fr: 'Programmation Android de zéro avec Java +40 heures - Jose Javier Villena',
    ru: 'Программирование для Android с нуля на Java, 40+ часов - Jose Javier Villena'
  },
  {
    es: 'Curso que abarca desde los fundamentos de Java hasta el desarrollo de aplicaciones completas para Android usando Android Studio. Se cubren temas como el diseño de interfaces con Material Design y Responsive Design, persistencia de datos mediante Shared Preferences, List View, Grid View, Card View y Recycler View, Fragments, Tabs y Toolbars, administración de bases de datos y la integración de GPS y Google Maps. Con más de 20 horas de contenido práctico, el curso permite crear aplicaciones funcionales.',
    en: 'Course covering everything from Java fundamentals to the development of complete Android applications using Android Studio. Topics include interface design with Material Design and Responsive Design, data persistence with Shared Preferences, List View, Grid View, Card View, and Recycler View, Fragments, Tabs, and Toolbars, database administration, and GPS and Google Maps integration. With more than 20 hours of practical content, the course enables the creation of functional applications.',
    de: 'Kurs, der von den Grundlagen von Java bis zur Entwicklung vollständiger Android-Anwendungen mit Android Studio reicht. Behandelt werden Themen wie Oberflächendesign mit Material Design und Responsive Design, Datenpersistenz mit Shared Preferences, List View, Grid View, Card View und Recycler View, Fragments, Tabs und Toolbars, Datenbankverwaltung sowie die Integration von GPS und Google Maps. Mit mehr als 20 Stunden praktischem Inhalt ermöglicht der Kurs die Erstellung funktionsfähiger Anwendungen.',
    fr: "Cours couvrant aussi bien les bases de Java que le développement d’applications Android complètes avec Android Studio. Les sujets abordés incluent la conception d’interfaces avec Material Design et Responsive Design, la persistance des données via Shared Preferences, List View, Grid View, Card View et Recycler View, les Fragments, Tabs et Toolbars, l’administration de bases de données ainsi que l’intégration du GPS et de Google Maps. Avec plus de 20 heures de contenu pratique, le cours permet de créer des applications fonctionnelles.",
    ru: 'Курс, охватывающий путь от основ Java до разработки полноценных Android-приложений в Android Studio. Рассматриваются дизайн интерфейсов с Material Design и Responsive Design, хранение данных через Shared Preferences, List View, Grid View, Card View и Recycler View, Fragments, Tabs и Toolbars, администрирование баз данных, а также интеграция GPS и Google Maps. Более 20 часов практического контента позволяют создавать рабочие приложения.'
  },
  {
    es: 'Lenguaje Ensamblador x86 Desde Cero - Lucas Bazilio',
    en: 'x86 Assembly Language from Scratch - Lucas Bazilio',
    de: 'x86-Assemblersprache von Grund auf - Lucas Bazilio',
    fr: "Langage assembleur x86 depuis zéro - Lucas Bazilio",
    ru: 'Язык ассемблера x86 с нуля - Lucas Bazilio'
  },
  {
    es: 'Curso que abarca los siguientes temas de lenguaje ensamblador x86: conjunto de instrucciones básicas, algoritmos matemáticos, tablas de búsqueda y tablas de salto, sintaxis de ensamblador MASM, algoritmos de procesamiento de imágenes, escritura de código ensamblador sólido mixto, traducción de lenguaje de alto nivel en C a ensamblador x86.',
    en: 'Course covering the following x86 assembly language topics: basic instruction set, mathematical algorithms, lookup tables and jump tables, MASM assembly syntax, image processing algorithms, writing solid mixed assembly code, and translating high-level C language into x86 assembly.',
    de: 'Kurs zu folgenden Themen der x86-Assemblersprache: grundlegender Befehlssatz, mathematische Algorithmen, Lookup-Tabellen und Sprungtabellen, MASM-Assemblersyntax, Bildverarbeitungsalgorithmen, Schreiben soliden gemischten Assembliercodes sowie Übersetzung von Hochsprache C in x86-Assembler.',
    fr: "Cours couvrant les sujets suivants en langage assembleur x86 : jeu d’instructions de base, algorithmes mathématiques, tables de recherche et tables de saut, syntaxe assembleur MASM, algorithmes de traitement d’images, écriture de code assembleur mixte robuste et traduction du langage C de haut niveau vers l’assembleur x86.",
    ru: 'Курс охватывает следующие темы по ассемблеру x86: базовый набор инструкций, математические алгоритмы, таблицы поиска и таблицы переходов, синтаксис MASM, алгоритмы обработки изображений, написание надежного смешанного ассемблерного кода и перевод высокоуровневого языка C в ассемблер x86.'
  },
  {
    es: 'Reparación de computadoras - Comunidad reparando',
    en: 'Computer repair - Comunidad reparando',
    de: 'Computerreparatur - Comunidad reparando',
    fr: "Réparation d'ordinateurs - Comunidad reparando",
    ru: 'Ремонт компьютеров - Comunidad reparando'
  },
  {
    es: 'Curso que abarca tanto hardware (mantenimiento preventivo, tratamiento contra polvo y humedad, reemplazo de componentes estropeados, arquitectura general de hardware de PC, etc.) como software (virus y cualquier tipo de malware, actualizaciones, respaldos, etc.) para enseñar al alumno a resolver dicha clase de conflictos.',
    en: 'Course covering both hardware (preventive maintenance, dust and humidity treatment, replacement of damaged components, general PC hardware architecture, etc.) and software (viruses and all kinds of malware, updates, backups, etc.) to teach students how to solve this type of issue.',
    de: 'Kurs, der sowohl Hardware (präventive Wartung, Schutz vor Staub und Feuchtigkeit, Austausch beschädigter Komponenten, allgemeine PC-Hardwarearchitektur usw.) als auch Software (Viren und jede Art von Malware, Updates, Backups usw.) behandelt, um Lernende zur Lösung dieser Art von Problemen zu befähigen.',
    fr: "Cours couvrant à la fois le matériel (maintenance préventive, traitement contre la poussière et l’humidité, remplacement de composants endommagés, architecture générale du matériel PC, etc.) et le logiciel (virus et tout type de malware, mises à jour, sauvegardes, etc.) afin d’apprendre à l’élève à résoudre ce type de problèmes.",
    ru: 'Курс, охватывающий как аппаратную часть (профилактическое обслуживание, защита от пыли и влаги, замена поврежденных компонентов, общая архитектура ПК и т.д.), так и программную (вирусы и любое вредоносное ПО, обновления, резервные копии и т.д.), чтобы научить ученика решать подобные проблемы.'
  },
  {
    es: 'Inglés B2: Intermedio - avanzado (conversacional)',
    en: 'English B2: Intermediate - advanced (conversational)',
    de: 'Englisch B2: Mittelstufe - fortgeschritten (Konversation)',
    fr: 'Anglais B2 : intermédiaire - avancé (conversationnel)',
    ru: 'Английский B2: средний - продвинутый (разговорный)'
  },
  {
    es: 'Español C1: Nativo',
    en: 'Spanish C1: Native',
    de: 'Spanisch C1: Muttersprache',
    fr: 'Espagnol C1 : langue maternelle',
    ru: 'Испанский C1: родной'
  },
  {
    es: 'Rápido aprendizaje y enfoque autodidacta',
    en: 'Fast learner and self-taught approach',
    de: 'Schnelles Lernen und autodidaktischer Ansatz',
    fr: 'Apprentissage rapide et approche autodidacte',
    ru: 'Быстрое обучение и самообразовательный подход'
  },
  {
    es: 'Pensamiento abstracto',
    en: 'Abstract thinking',
    de: 'Abstraktes Denken',
    fr: 'Pensée abstraite',
    ru: 'Абстрактное мышление'
  },
  {
    es: 'Creatividad e ingenio',
    en: 'Creativity and ingenuity',
    de: 'Kreativität und Einfallsreichtum',
    fr: 'Créativité et ingéniosité',
    ru: 'Креативность и находчивость'
  },
  {
    es: 'Curiosidad e interés',
    en: 'Curiosity and interest',
    de: 'Neugier und Interesse',
    fr: 'Curiosité et intérêt',
    ru: 'Любознательность и интерес'
  },
  {
    es: 'Responsabilidad',
    en: 'Responsibility',
    de: 'Verantwortung',
    fr: 'Responsabilité',
    ru: 'Ответственность'
  },
  {
    es: 'Resiliencia',
    en: 'Resilience',
    de: 'Resilienz',
    fr: 'Résilience',
    ru: 'Устойчивость'
  },
  {
    es: 'Compromiso',
    en: 'Commitment',
    de: 'Engagement',
    fr: 'Engagement',
    ru: 'Вовлеченность'
  },
  {
    es: 'Adaptación al cambio',
    en: 'Adaptability to change',
    de: 'Anpassungsfähigkeit an Veränderungen',
    fr: 'Adaptation au changement',
    ru: 'Адаптация к изменениям'
  },
  {
    es: 'C y C++',
    en: 'C and C++',
    de: 'C und C++',
    fr: 'C et C++',
    ru: 'C и C++'
  },
  {
    es: 'Otros: C#, Dart, Pascal, Ensamblador x86, Visual Basic (en Excel)',
    en: 'Others: C#, Dart, Pascal, x86 Assembly, Visual Basic (in Excel)',
    de: 'Weitere: C#, Dart, Pascal, x86-Assembler, Visual Basic (in Excel)',
    fr: 'Autres : C#, Dart, Pascal, assembleur x86, Visual Basic (dans Excel)',
    ru: 'Другие: C#, Dart, Pascal, ассемблер x86, Visual Basic (в Excel)'
  },
  {
    es: 'Git y GitHub',
    en: 'Git and GitHub',
    de: 'Git und GitHub',
    fr: 'Git et GitHub',
    ru: 'Git и GitHub'
  },
  {
    es: 'Operaciones CRUD y diseño de bases de datos SQL',
    en: 'CRUD operations and SQL database design',
    de: 'CRUD-Operationen und SQL-Datenbankdesign',
    fr: 'Opérations CRUD et conception de bases de données SQL',
    ru: 'CRUD-операции и проектирование SQL-баз данных'
  },
  {
    es: 'Algoritmos de machine learning y deep learning',
    en: 'Machine learning and deep learning algorithms',
    de: 'Machine-Learning- und Deep-Learning-Algorithmen',
    fr: 'Algorithmes de machine learning et de deep learning',
    ru: 'Алгоритмы машинного и глубокого обучения'
  },
  {
    es: 'Estructuras de datos',
    en: 'Data structures',
    de: 'Datenstrukturen',
    fr: 'Structures de données',
    ru: 'Структуры данных'
  },
  {
    es: 'Fundamentos de ciberseguridad',
    en: 'Cybersecurity fundamentals',
    de: 'Grundlagen der Cybersicherheit',
    fr: 'Fondamentaux de la cybersécurité',
    ru: 'Основы кибербезопасности'
  },
  {
    es: 'Programación orientada a objetos',
    en: 'Object-oriented programming',
    de: 'Objektorientierte Programmierung',
    fr: 'Programmation orientée objet',
    ru: 'Объектно-ориентированное программирование'
  },
  {
    es: 'Instalación y uso de múltiples S.O. Windows y Linux',
    en: 'Installation and use of multiple Windows and Linux operating systems',
    de: 'Installation und Nutzung mehrerer Windows- und Linux-Betriebssysteme',
    fr: 'Installation et utilisation de plusieurs systèmes Windows et Linux',
    ru: 'Установка и использование нескольких ОС Windows и Linux'
  },
  {
    es: 'Mantenimiento preventivo de hardware',
    en: 'Preventive hardware maintenance',
    de: 'Präventive Hardware-Wartung',
    fr: 'Maintenance préventive du matériel',
    ru: 'Профилактическое обслуживание оборудования'
  },
  {
    es: 'Programación en Excel con Visual Basic',
    en: 'Excel programming with Visual Basic',
    de: 'Programmierung in Excel mit Visual Basic',
    fr: 'Programmation dans Excel avec Visual Basic',
    ru: 'Программирование в Excel с Visual Basic'
  }
];

export function normalizeText(value: string): string {
  return value.replace(/\s+/g, ' ').trim();
}

export const CONTENT_TRANSLATIONS = Object.fromEntries(
  contentEntries.map(({ es, ...translations }) => [normalizeText(es), translations])
) satisfies Record<string, Record<Exclude<LanguageCode, 'es'>, string>>;

export type UiTextKey = keyof typeof UI_TEXTS;
